--ctypedef--
typedef struct td_delete_cb delete_cb;
typedef struct td_delete_cb_list delete_cb_list;
--ctypedef--

--cstruct--
struct td_delete_cb {
    void* _parent;
    void (*_cb)(void* _parent, void* object);
};

struct td_delete_cb_list {
    int size;
    delete_cb cb[5];
    delete_cb_list* next;
};
--cstruct--

--cdefine--
uint32_t void_hash(void* p);
int void_equal(void *p1, void* p2);
void delete_cb_list_free(delete_cb_list* d);
void delete_cb_list_add(delete_cb_list* d, delete_cb cb);
void delete_cb_list_remove(delete_cb_list* d, delete_cb cb);
void delete_cb_list_invoke(delete_cb_list* d, void* p);
void weakptr_init();
void weakptr_release(void* v);
void weakptr_cb_add(void* v, delete_cb cb);
void weakptr_cb_remove(void* v, delete_cb cb);
void ptr_init();
void ptr_retain(void* ptr);
bool ptr_release(void* ptr);
--cdefine--

--cfunction--
uint32_t void_hash(void* p) {
    return kh_int_hash_func((uintptr_t)p);
}

int void_equal(void *p1, void* p2) {
    return (p1 == p2);
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

KHASH_INIT(weakptr_hash_type, void*, delete_cb_list, 1, void_hash, void_equal)
khash_t(weakptr_hash_type)* weakptr_hash;

void weakptr_init() {
    weakptr_hash = kh_init(weakptr_hash_type);
}

void weakptr_release(void* v) {
    khiter_t k = kh_get(weakptr_hash_type, weakptr_hash, v);
    if (k != kh_end(weakptr_hash)) {
        delete_cb_list* d = &kh_value(weakptr_hash, k);
        delete_cb_list_invoke(d, v);
        if (d->next) {
            delete_cb_list_free(d->next);
        }
        kh_del(weakptr_hash_type, weakptr_hash, k);
    }
}

void weakptr_cb_add(void* v, delete_cb cb) {
    delete_cb_list* d;
    khiter_t k = kh_get(weakptr_hash_type, weakptr_hash, v);
    if (k == kh_end(weakptr_hash)) {
        int ret;
        khiter_t k = kh_put(weakptr_hash_type, weakptr_hash, v, &ret);
        if (!ret) kh_del(weakptr_hash_type, weakptr_hash, k);
        d = &kh_value(weakptr_hash, k);
        d->size = 0;
        d->next = 0;
    }
    else {
        d = &kh_value(weakptr_hash, k);
    }
    delete_cb_list_add(d, cb);
}

void weakptr_cb_remove(void* v, delete_cb cb) {
    khiter_t k = kh_get(weakptr_hash_type, weakptr_hash, v);
    if (k != kh_end(weakptr_hash)) {
        delete_cb_list* d = &kh_value(weakptr_hash, k);
        delete_cb_list_remove(d, cb);
    }
}

KHASH_INIT(ptr_hash_type, void*, int, 1, void_hash, void_equal)
khash_t(ptr_hash_type)* ptr_hash;

void ptr_init() {
    ptr_hash = kh_init(ptr_hash_type);
}

void ptr_retain(void* v) {
    khiter_t k = kh_get(ptr_hash_type, ptr_hash, v);
    if (k == kh_end(ptr_hash)) {
        int ret;
        khiter_t k = kh_put(ptr_hash_type, ptr_hash, v, &ret);
        if (!ret) kh_del(ptr_hash_type, ptr_hash, k);
        kh_value(ptr_hash, k) = 1;
    }
    else {
        kh_value(ptr_hash, k)++;
    }
}

bool ptr_release(void* v) {
    khiter_t k = kh_get(ptr_hash_type, ptr_hash, v);
    if (k != kh_end(ptr_hash)) {
        kh_value(ptr_hash, k)--;
        if (kh_value(ptr_hash, k) == 0) {
            kh_del(ptr_hash_type, ptr_hash, k);
        }
        return false;
    }
    return true;
}
--cfunction--

--c--
ptr_init();
weakptr_init();
--c--