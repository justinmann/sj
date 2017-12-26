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