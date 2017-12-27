void halt(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
#ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
#endif
    exit(-1);
}

void debugout(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
}

void debugoutv(const char * format, va_list args) {
#ifdef _WINDOWS
    char text[1024];
    vsnprintf(text, sizeof(text), format, args);
    OutputDebugStringA(text);
#else
    vfprintf(stderr, format, args);
#endif
}

void ptr_hash(void* p, uint32_t* result) {
#ifdef __32__
    *result = kh_int_hash_func((uintptr_t)p);
#else
    *result = kh_int64_hash_func((uintptr_t)p);
#endif
}

void ptr_isequal(void *p1, void* p2, bool* result) {
    *result = (p1 == p2);
}

void delete_cb_list_free(delete_cb_list* d) {
    if (d->next) {
        delete_cb_list_free(d->next);
    }
    free(d);
}

void delete_cb_list_add(delete_cb_list* d, delete_cb cb) {
    if (d->size < 5) {
        d->cb[d->size] = cb;
        d->size++;
    }
    else {
        if (!d->next) {
            d->next = (delete_cb_list*)malloc(sizeof(delete_cb_list));
        }
        delete_cb_list_add(d->next, cb);
    }
}

void delete_cb_list_remove(delete_cb_list* d, delete_cb cb) {
    for (int i = 0; i < d->size; i++) {
        if (d->cb[i]._parent == cb._parent && d->cb[i]._cb == cb._cb) {
            for (int j = i; j < d->size - 1; j++) {
                d->cb[j] = d->cb[j + 1];
            }
            d->size--;
        }
    }

    if (d->next) {
        delete_cb_list_remove(d->next, cb);
    }
}

void delete_cb_list_invoke(delete_cb_list* d, void* p) {
    for (int i = 0; i < d->size; i++) {
        d->cb[i]._cb(d->cb[i]._parent, p);
    }

    if (d->next) {
        delete_cb_list_invoke(d->next, p);
    }
}

KHASH_INIT_TYPEDEF(weakptr_hashtable_type, void*, delete_cb_list)
KHASH_INIT_FUNCTION(weakptr_hashtable_type, void*, delete_cb_list, 1, ptr_hash, ptr_isequal)
khash_t(weakptr_hashtable_type)* weakptr_hashtable;

void weakptr_init() {
    weakptr_hashtable = kh_init(weakptr_hashtable_type);
}

void weakptr_release(void* v) {
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k != kh_end(weakptr_hashtable)) {
        delete_cb_list* d = &kh_value(weakptr_hashtable, k);
        delete_cb_list_invoke(d, v);
        if (d->next) {
            delete_cb_list_free(d->next);
        }
        kh_del(weakptr_hashtable_type, weakptr_hashtable, k);
    }
}

void weakptr_cb_add(void* v, delete_cb cb) {
    delete_cb_list* d;
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k == kh_end(weakptr_hashtable)) {
        int ret;
        khiter_t k = kh_put(weakptr_hashtable_type, weakptr_hashtable, v, &ret);
        if (!ret) kh_del(weakptr_hashtable_type, weakptr_hashtable, k);
        d = &kh_value(weakptr_hashtable, k);
        d->size = 0;
        d->next = 0;
    }
    else {
        d = &kh_value(weakptr_hashtable, k);
    }
    delete_cb_list_add(d, cb);
}

void weakptr_cb_remove(void* v, delete_cb cb) {
    khiter_t k = kh_get(weakptr_hashtable_type, weakptr_hashtable, v);
    if (k != kh_end(weakptr_hashtable)) {
        delete_cb_list* d = &kh_value(weakptr_hashtable, k);
        delete_cb_list_remove(d, cb);
    }
}

KHASH_INIT_TYPEDEF(ptr_hashtable_type, void*, int)
KHASH_INIT_FUNCTION(ptr_hashtable_type, void*, int, 1, ptr_hash, ptr_isequal)
khash_t(ptr_hashtable_type)* ptr_hashtable;

void ptr_init() {
    ptr_hashtable = kh_init(ptr_hashtable_type);
}

void ptr_retain(void* v) {
    khiter_t k = kh_get(ptr_hashtable_type, ptr_hashtable, v);
    if (k == kh_end(ptr_hashtable)) {
        int ret;
        khiter_t k = kh_put(ptr_hashtable_type, ptr_hashtable, v, &ret);
        if (!ret) kh_del(ptr_hashtable_type, ptr_hashtable, k);
        kh_value(ptr_hashtable, k) = 1;
    }
    else {
        kh_value(ptr_hashtable, k)++;
    }
}

bool ptr_release(void* v) {
    khiter_t k = kh_get(ptr_hashtable_type, ptr_hashtable, v);
    if (k != kh_end(ptr_hashtable)) {
        kh_value(ptr_hashtable, k)--;
        if (kh_value(ptr_hashtable, k) == 0) {
            kh_del(ptr_hashtable_type, ptr_hashtable, k);
        }
        return false;
    }
    return true;
}

void weakptr_clear(void* parent, void* v) {
    void** p = (void**)parent;
    if (*p != v) {
        halt("weakptr was changed without clearing callback");
    }
    *p = 0;
}

typedef struct {
	int typeid;
	char** retain_func_names;
	int retain_func_names_count;
	int retain_func_names_size;
	char** release_func_names;
	int release_func_names_count;
	int release_func_names_size;
} _object_data;

KHASH_INIT_TYPEDEF(_object_hashtable_type, sjs_object*, _object_data)
KHASH_INIT_FUNCTION(_object_hashtable_type, sjs_object*, _object_data, 1, ptr_hash, ptr_isequal)
khash_t(_object_hashtable_type)* _object_hashtable;

void _object_start() {
    _object_hashtable = kh_init(_object_hashtable_type);
}

void _object_init(sjs_object* obj, int typeid, char* funcname) {
	// debugout("_object_init %d %0x %s\n", typeid, obj, funcname);

    khiter_t k = kh_get(_object_hashtable_type, _object_hashtable, obj);
    if (k != kh_end(_object_hashtable)) {
    	halt("object %x init twice\n");
    }

    int ret;
    k = kh_put(_object_hashtable_type, _object_hashtable, obj, &ret);
    if (!ret) kh_del(_object_hashtable_type, _object_hashtable, k);
    kh_value(_object_hashtable, k).typeid = typeid;
    kh_value(_object_hashtable, k).retain_func_names_size = 10;
    kh_value(_object_hashtable, k).retain_func_names = malloc(sizeof(char*) * kh_value(_object_hashtable, k).retain_func_names_size);
    kh_value(_object_hashtable, k).retain_func_names[0] = funcname;
    kh_value(_object_hashtable, k).retain_func_names_count = 1;
    kh_value(_object_hashtable, k).release_func_names_size = 10;
    kh_value(_object_hashtable, k).release_func_names = malloc(sizeof(char*) * kh_value(_object_hashtable, k).release_func_names_size);
    kh_value(_object_hashtable, k).release_func_names_count = 0;
}

void _object_retain(sjs_object* obj, char* funcname) {
    // debugout("_object_retain %0x %s\n", obj, funcname);

    khiter_t k = kh_get(_object_hashtable_type, _object_hashtable, obj);
    if (k == kh_end(_object_hashtable)) {
    	halt("object %x was not init'ed\n");
    }
    kh_value(_object_hashtable, k).retain_func_names[kh_value(_object_hashtable, k).retain_func_names_count] = funcname;
    kh_value(_object_hashtable, k).retain_func_names_count++;
    if (kh_value(_object_hashtable, k).retain_func_names_count >= kh_value(_object_hashtable, k).retain_func_names_size) {
    	kh_value(_object_hashtable, k).retain_func_names_size += 100;
	    kh_value(_object_hashtable, k).retain_func_names = realloc(
            kh_value(_object_hashtable, k).retain_func_names, 
            sizeof(char*) * kh_value(_object_hashtable, k).retain_func_names_size);
    }

    if (obj->_refCount != kh_value(_object_hashtable, k).retain_func_names_count - kh_value(_object_hashtable, k).release_func_names_count) {
    	halt("retain/release was missed\n");    	
    }
}

void _object_release(sjs_object* obj, char* funcname) {
    // debugout("_object_release %0x %s\n", obj, funcname);

    khiter_t k = kh_get(_object_hashtable_type, _object_hashtable, obj);
    if (k == kh_end(_object_hashtable)) {
    	halt("object %x was not init'ed\n");
    }
    kh_value(_object_hashtable, k).release_func_names[kh_value(_object_hashtable, k).release_func_names_count] = funcname;
    kh_value(_object_hashtable, k).release_func_names_count++;
    if (kh_value(_object_hashtable, k).release_func_names_count >= kh_value(_object_hashtable, k).release_func_names_size) {
    	kh_value(_object_hashtable, k).release_func_names_size += 100;
	    kh_value(_object_hashtable, k).release_func_names = realloc(
            kh_value(_object_hashtable, k).release_func_names, 
            sizeof(char*) * kh_value(_object_hashtable, k).release_func_names_size);
    }

    if (obj->_refCount != kh_value(_object_hashtable, k).retain_func_names_count - kh_value(_object_hashtable, k).release_func_names_count) {
    	halt("retain/release was missed\n");    	
    }

    if (obj->_refCount == 0) {
    	free(kh_value(_object_hashtable, k).retain_func_names);
    	free(kh_value(_object_hashtable, k).release_func_names);
        kh_del(_object_hashtable_type, _object_hashtable, k);
    }
}

void _object_report() {
	debugout("_object_report\n");

    for (khiter_t k = kh_begin(_object_hashtable); k != kh_end(_object_hashtable); ++k) {
        if (kh_exist(_object_hashtable, k)) {
        	debugout("%0x typeid: %d refcount: %d\n", kh_key(_object_hashtable, k), kh_value(_object_hashtable, k).typeid, kh_key(_object_hashtable, k)->_refCount);

            for (int i = 0; i < kh_value(_object_hashtable, k).retain_func_names_count; i++) {
	        	debugout("\tretain: %s\n", kh_value(_object_hashtable, k).retain_func_names[i]);
        	}
        	
        	for (int i = 0; i < kh_value(_object_hashtable, k).release_func_names_count; i++) {
	        	debugout("\trelease: %s\n", kh_value(_object_hashtable, k).release_func_names[i]);
        	}
        }
    }
}