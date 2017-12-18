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
        kh_destroy(#safeName(key)_#safeName(val)_hash_type, _this->_hash);
    }
    --c--
}