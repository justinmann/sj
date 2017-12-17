hash![key, val] (
    --cvar--
    khash_t(#type(key)_#type(val)_hash_type)* _hash;
    --cvar--

    setAt(key : 'key, val : 'val) {
        --c--
        khiter_t k = kh_get(#type(key)_#type(val)_hash_type, _hash, key);
        if (k != kh_end(_hash)) {
            #release(val, kh_val(_hash, k));
        }

        int ret;
        khiter_t k = kh_put(#type(key)_#type(val)_hash_type, _hash, val, &ret);
        if (!ret) kh_del(#type(key)_#type(val)_hash_type, _hash, key);
        #retain(val, kh_val(_hash, k), val);
        --c--
    }

    getAt(k : 'key)'val {
        --c--
        khiter_t k = kh_get(#type(key)_#type(val)_hash_type, _hash, key);
        if (k == kh_end(_hash)) {
            halt("cannot find key");
        }
        #return(val, kh_val(_hash, k));
        --c--
    }
) {
    --cfunction--
    KHASH_INIT(#type(key)_#type(val)_type, #type(key), #type(val), 1, #functionStack(key, hash), #functionStack(key, isEqual))
    --cfunction--
    --c--
    _hash = kh_init(#type(key)_#type(val)_hash_type);
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
        kh_destroy(#type(key)_#type(val)_hash_type, _hash);
    }
    --c--
}