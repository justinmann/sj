hash![key, val] (
    --cvar--
    void* _hash;
    --cvar--

    getCount() {
        --c--
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;
        int x = kh_size(p);
        #return(i32, x);
        --c--   
    }

    resize(newBuckets : 'i32) {
        --c--
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;
        kh_resize(#safeName(key)_#safeName(val)_hash_type, p, newbuckets);
        --c--   
    }

    getAt(key : 'key)'val? {
        --c--
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;
    
    ##if #isStack(key)
        khiter_t k = kh_get(#safeName(key)_#safeName(val)_hash_type, p, *key);
    ##else
        khiter_t k = kh_get(#safeName(key)_#safeName(val)_hash_type, p, key);
    ##endif

        if (k == kh_end(p)) {
            #returnEmpty(val)
        }
        #returnValue(val, kh_val(p, k));
        --c--
    }

    setAt(key : 'key, val : 'val) {
        --c--
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;

    ##if #isStack(key)
        khiter_t k = kh_get(#safeName(key)_#safeName(val)_hash_type, p, *key);
    ##else
        khiter_t k = kh_get(#safeName(key)_#safeName(val)_hash_type, p, key);
    ##endif

        if (k != kh_end(p)) {            
            #release(val, kh_val(p, k));
        }

        int ret;
    ##if #isStack(key)
        k = kh_put(#safeName(key)_#safeName(val)_hash_type, _parent->_hash, *key, &ret);
    ##else
        k = kh_put(#safeName(key)_#safeName(val)_hash_type, _parent->_hash, key, &ret);
    ##endif

        if (!ret) kh_del(#safeName(key)_#safeName(val)_hash_type, p, k);

    ##if #isWeak(key)
        delete_cb cb = { _parent, (void(*)(void*, void*))#functionStack(parent, _weakPtrRemoveKey) };
        weakptr_cb_add(#parent(key, key), cb);
    ##else
        #type(key) t;
        #retain(key, t, key);
    ##endif

    ##if #isWeak(val)
        delete_cb cb = { _parent, (void(*)(void*, void*))#functionStack(parent, _weakPtrRemoveValue) };
        weakptr_cb_add(#parent(val, val), cb);
        kh_val(p, k) = val;
    ##else
        #retain(val, kh_val(p, k), val);
    ##endif
        --c--
    }

    remove(key : 'key) {
        --c--
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;

    ##if #isStack(key)
        khiter_t k = kh_get(#safeName(key)_#safeName(val)_hash_type, p, *key);
    ##else
        khiter_t k = kh_get(#safeName(key)_#safeName(val)_hash_type, p, key);
    ##endif

        if (k != kh_end(p)) {            
            #release(val, kh_val(p, k));
            kh_del(#safeName(key)_#safeName(val)_hash_type, p, k);
        }
        --c--    
    }

    each(cb : '(:key,:val)void)'void {
        --c--
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                cb._cb(
                    cb._parent, 
    ##if #isStack(key)
                    &kh_key(p, k), 
    ##else
                    kh_key(p, k), 
    ##endif

    ##if #isStack(val)
                    &kh_value(p, k)
    ##else
                    kh_value(p, k)
    ##endif
                );
            }
        }
        --c--
    }

    filter(cb : '(:key,:val)bool)'hash![key, val] {
        newHash : hash![key, val]()
        --c--
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;
        khash_t(#safeName(key)_#safeName(val)_hash_type)* newP = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)sjv_newHash->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                bool result;
                cb._cb(
                    cb._parent, 
    ##if #isStack(key)
                    &kh_key(p, k), 
    ##else
                    kh_key(p, k), 
    ##endif

    ##if #isStack(val)
                    &kh_value(p, k), 
    ##else
                    kh_value(p, k), 
    ##endif
                    &result
                );

                if (result) {
                    int ret;
                    khiter_t k = kh_put(#safeName(key)_#safeName(val)_hash_type, newP, kh_key(p, k), &ret);
                    if (!ret) kh_del(#safeName(key)_#safeName(val)_hash_type, newP, k);

    ##if #isWeak(key)
                    delete_cb cb = { sjv_newHash, (void(*)(void*, void*))#functionStack(parent, _weakPtrRemoveKey) };
                    weakptr_cb_add(#parent(key, kh_key(newP, k)), cb);
    ##else
                    #type(key) t;
                    #retain(key, t, kh_key(p, k));
    ##endif

    ##if #isWeak(val)
                    delete_cb cb = { sjv_newHash, (void(*)(void*, void*))#functionStack(parent, _weakPtrRemoveValue) };
                    weakptr_cb_add(#parent(val, kh_val(newP, k)), cb);
    ##else
                    #retain(val, kh_val(newP, k), kh_value(p, k));
    ##endif
                }
            }
        }
        --c--
        newHash
    }

    foldl!result(initial : 'result, cb : '(:result,:key,:val)result)'result {
        r := initial
        for i : 0 to count {
            r = cb(r, getAt(i))
        }           
        r
    }

    _weakPtrRemoveKey(key : 'key) {
        --c--
    ##if #isWeak(key)
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;    
        khiter_t k = kh_get(#safeName(key)_#safeName(val)_hash_type, p, key);
        if (k != kh_end(p)) {
            kh_del(#safeName(key)_#safeName(val)_hash_type, p, k);
        }
    ##endif
        --c--
    }

    _weakPtrRemoveValue(val : 'val) {
        --c--
    ##if #isWeak(val)
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_parent->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #type(val) t = kh_value(p, k);
                if #isPtrEqual(val, t, val) {
                    kh_del(#safeName(key)_#safeName(val)_hash_type, p, k);
                }
            }
        }
    ##endif
        --c--
    }
) {
    --cdefine--
    ##ifndef #safeName(key)_#safeName(val)_hash_typedef
    ##define #safeName(key)_#safeName(val)_hash_typedef
    KHASH_INIT_TYPEDEF(#safeName(key)_#safeName(val)_hash_type, #type(key), #type(val))
    ##endif
    --cdefine--

    --cfunction--
    ##ifndef #safeName(key)_#safeName(val)_hash_function
    ##define #safeName(key)_#safeName(val)_hash_function
    ##if #isStack(key)
    KHASH_INIT_FUNCTION_DEREF(#safeName(key)_#safeName(val)_hash_type, #type(key), #type(val), 1, #functionStack(key, hash), #functionStack(key, isEqual))
    ##else
    KHASH_INIT_FUNCTION(#safeName(key)_#safeName(val)_hash_type, #type(key), #type(val), 1, #functionStack(key, hash), #functionStack(key, isEqual))
    ##endif
    ##endif
    --cfunction--

    --c--
    _this->_hash = kh_init(#safeName(key)_#safeName(val)_hash_type);
    --c--
    this
} copy {
    --c--
    _this->_hash = _from->_hash;
    khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_this->_hash;
    p->refcount++;
    --c--
} destroy {
    --c--
    khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_this->_hash;
    p->refcount--;
    if (p->refcount == 0) {
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
    
    ##if #isWeak(key)
                delete_cb cb = { p, (void(*)(void*, void*))#functionStack(this, _weakPtrRemoveKey) };
                weakptr_cb_remove(#parent(key, kh_key(p, k)), cb);
    ##else
                #release(key, kh_key(p, k));
    ##endif

    ##if #isWeak(val)
                delete_cb cb = { p, (void(*)(void*, void*))#functionStack(this, _weakPtrRemoveValue) };
                weakptr_cb_remove(#parent(val, kh_value(p, k)), cb);
    ##else
                #release(val, kh_value(p, k));
    ##endif
            }
        }
        kh_destroy(#safeName(key)_#safeName(val)_hash_type, _this->_hash);
    }
    --c--
}