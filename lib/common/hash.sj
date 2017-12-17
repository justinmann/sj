hash![key, val] (
    --cvar--
    khash_t(#type(key)_#type(val)_hash_type)* _hash;
    --cvar--

    setAt(key : 'key, val : 'val) {
        --c--
        khiter_t k = kh_get(#type(key)_#type(val)_hash_type, _parent->_hash, key);
        if (k != kh_end(_parent->_hash)) {            
            #release(val, kh_val(_parent->_hash, k));
        }

        int ret;
        k = kh_put(#type(key)_#type(val)_hash_type, _parent->_hash, key, &ret);
        if (!ret) kh_del(#type(key)_#type(val)_hash_type, _parent->_hash, key);
        #retain(val, kh_val(_parent->_hash, k), val);
        --c--
    }

    getAt(key : 'key)'val {
        --c--
        khiter_t k = kh_get(#type(key)_#type(val)_hash_type, _parent->_hash, key);
        if (k == kh_end(_parent->_hash)) {
            halt("cannot find key");
        }
        #return(val, kh_val(_parent->_hash, k));
        --c--
    }
) {
    --cstruct--
    ##ifndef #type(key)_#type(val)_hash_typedef
    ##define #type(key)_#type(val)_hash_typedef
    KHASH_INIT_TYPEDEF(#type(key)_#type(val)_hash_type, #type(key), #type(val))
    ##endif
    --cstruct--

    --cfunction--
    ##ifndef #type(key)_#type(val)_hash_function
    ##define #type(key)_#type(val)_hash_function
    KHASH_INIT_FUNCTION(#type(key)_#type(val)_hash_type, #type(key), #type(val), 1, #functionStack(key, hash), #functionStack(key, isEqual))
    ##endif
    --cfunction--

    --c--
    _this->_hash = kh_init(#type(key)_#type(val)_hash_type);
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
        kh_destroy(#type(key)_#type(val)_hash_type, _this->_hash);
    }
    --c--
}