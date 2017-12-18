hash![key, val] (
    --cvar--
    void* _hash;
    --cvar--

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

        #type(key) t;
        #retain(key, t, key);
        #retain(val, kh_val(p, k), val);
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
    ##if #isStack(key)
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
    ##if #isStack(key)
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
                    #type(key) t;
                    #retain(key, t, kh_key(p, k));
                    #retain(val, kh_val(newP, k), kh_value(p, k));
                }
            }
        }
        --c--
        copy newHash
    }

    foldl!result(initial : 'result, cb : '(:result,:key,:val)result)'result {
        r := initial
        for i : 0 to count {
            r = cb(r, getAt(i))
        }           
        r
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
    KHASH_INIT_FUNCTION(#safeName(key)_#safeName(val)_hash_type, #type(key), #type(val), 1, #functionStack(key, hash), #functionStack(key, isEqual), &)
    ##else
    KHASH_INIT_FUNCTION(#safeName(key)_#safeName(val)_hash_type, #type(key), #type(val), 1, #functionStack(key, hash), #functionStack(key, isEqual), )
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
    ptr_retain(_this->_hash);
    --c--
} destroy {
    --c--
    if (ptr_release(_this->_hash)) {
        khash_t(#safeName(key)_#safeName(val)_hash_type)* p = (khash_t(#safeName(key)_#safeName(val)_hash_type)*)_this->_hash;
        for (khiter_t k = kh_begin(p); k != kh_end(p); ++k) {
            if (kh_exist(p, k)) {
                #release(key, kh_key(p, k));
                #release(val, kh_value(p, k));
            }
        }
        kh_destroy(#safeName(key)_#safeName(val)_hash_type, _this->_hash);
    }
    --c--
}