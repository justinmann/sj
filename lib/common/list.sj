list!t(
    array := array!t(0)

    getCount() {
        array.count
    }

    getAt(index : 'i32)'t {
        array.getAt(index)
    }

    setAt(index : 'i32, item : 't)'void {
        array.setAt(index, item)
    }

    each(cb : '(:t)void)'void {
        array.each(cb)
    }

    map!new_t(cb : '(:t)new_t)'array!new_t {
        array.map!new_t(cb)
    }

    sort() {
        array.sort()
    }

    sortcb(cb : '(:t, :t)i32) {
        array.sortcb(cb)
    }

    filter(cb : '(:t)bool)'list!t {
        list!t(array.filter(cb))
    }

    foldl!result(initial : 'result, cb : '(:result, :t)result)'result {
        array.foldl!result(cb)
    }

    foldr!result(initial : 'result, cb : '(:result, :t)result)'result {
        array.foldr!result(cb)
    }
    
    add(item :'t) {
        if array.count >= array.dataSize {
            array = copy array.grow(10.max(array.dataSize * 2))
            void
        }

        array.initAt(array.count, item)
    }

    removeAt(index : 'i32)'void {
        --c--
        if (index < 0 || index >= _parent->array.count) {
            halt("removeAt: out of bounds %d:%d\n", index, _parent->array.count);
        }
        #type(t)* p = (#type(t)*)_parent->array.data;
        #release(t, p[index]);
        if (index != _parent->array.count - 1) {
            memcpy(p + index, p + index + 1, (_parent->array.count - index - 1) * sizeof(#type(t)));
        }
        _parent->array.count--;
        --c--
    }
) { this }