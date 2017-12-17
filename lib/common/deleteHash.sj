--ctypedef--
typedef struct td_deleteCallback deleteCallback;
typedef struct td_deleteCallbacks deleteCallbacks;
--ctypedef--

--cstruct--
struct td_deleteCallback {
    void* _parent;
    void (*_cb)(void* _parent, void* object);
};

struct td_deleteCallbacks {
    int size;
    deleteCallback cb[5];
    deleteCallbacks* next;
};
--cstruct--

--cdefine--
void deleteCallbacks_free(deleteCallbacks* d);
void deleteCallbacks_add(deleteCallbacks* d, deleteCallback cb);
void deleteCallbacks_remove(deleteCallbacks* d, deleteCallback cb);
void deleteCallbacks_invoke(deleteCallbacks* d, void* p);
uint32_t void_hash(void* p);
int void_equal(void *p1, void* p2);
void deleteHash_init();
void deleteHash_invokeAndRemove(void* v);
void deleteHash_add(void* v, deleteCallback cb);
void deleteHash_remove(void* v, deleteCallback cb);
--cdefine--

--cfunction--
void deleteCallbacks_free(deleteCallbacks* d) {
    if (d->next) {
        deleteCallbacks_free(d->next);
    }
    free(d);
}

void deleteCallbacks_add(deleteCallbacks* d, deleteCallback cb) {
    if (d->size < 5) {
        d->cb[d->size] = cb;
        d->size++;
    }
    else {
        if (!d->next) {
            d->next = (deleteCallbacks*)malloc(sizeof(deleteCallbacks));
        }
        deleteCallbacks_add(d->next, cb);
    }
}

void deleteCallbacks_remove(deleteCallbacks* d, deleteCallback cb) {
    for (int i = 0; i < d->size; i++) {
        if (d->cb[i]._parent == cb._parent && d->cb[i]._cb == cb._cb) {
            for (int j = i; j < d->size - 1; j++) {
                d->cb[j] = d->cb[j + 1];
            }
            d->size--;
        }
    }

    if (d->next) {
        deleteCallbacks_remove(d->next, cb);
    }
}

void deleteCallbacks_invoke(deleteCallbacks* d, void* p) {
    for (int i = 0; i < d->size; i++) {
        d->cb[i]._cb(d->cb[i]._parent, p);
    }

    if (d->next) {
        deleteCallbacks_invoke(d->next, p);
    }
}

uint32_t void_hash(void* p) {
    return kh_int64_hash_func((uintptr_t)p);
}

int void_equal(void *p1, void* p2) {
    return (p1 == p2);
}

KHASH_INIT(deleteHash_type, void*, deleteCallbacks, 1, void_hash, void_equal)
khash_t(deleteHash_type) *deleteHash;

void deleteHash_init() {
    deleteHash = kh_init(deleteHash_type);
}

void deleteHash_invokeAndRemove(void* v) {
    khiter_t k = kh_get(deleteHash_type, deleteHash, v);
    if (k != kh_end(deleteHash)) {
        deleteCallbacks* d = &kh_value(deleteHash, k);
        deleteCallbacks_invoke(d, v);
        if (d->next) {
            deleteCallbacks_free(d->next);
        }
        kh_del(deleteHash_type, deleteHash, k);
    }
}

void deleteHash_add(void* v, deleteCallback cb) {
    deleteCallbacks* d;
    khiter_t k = kh_get(deleteHash_type, deleteHash, v);
    if (k == kh_end(deleteHash)) {
        int ret;
        khiter_t k = kh_put(deleteHash_type, deleteHash, v, &ret);
        if (!ret) kh_del(deleteHash_type, deleteHash, k);
        d = &kh_value(deleteHash, k);
        d->size = 0;
        d->next = 0;
    }
    else {
        d = &kh_value(deleteHash, k);
    }
    deleteCallbacks_add(d, cb);
}

void deleteHash_remove(void* v, deleteCallback cb) {
    khiter_t k = kh_get(deleteHash_type, deleteHash, v);
    if (k != kh_end(deleteHash)) {
        deleteCallbacks* d = &kh_value(deleteHash, k);
        deleteCallbacks_remove(d, cb);
    }
}
--cfunction--

--c--
deleteHash_init();
--c--