emptyStringData := nullptr
--c--
sjv_emptystringdata = "";
--c--

string(
    count := 0
    data := array!char(
        data : emptyStringData
        dataSize : 0
        count : 0
        isGlobal : true
    )
    _isNullTerminated := false

    add(item : 'string) {
        if item.count == 0 {
            string(count : count, data : copy data)         
        } else {
            newData : if count + item.count > data.dataSize {
                data.grow(((count + item.count - 1) / 256 + 1) * 256)
            } else {
                copy data
            }
            newCount := count

            for i : 0 to item.count {
                newData.initAt(newCount, item.getAt(i))
                newCount++      
            }

            string(count : newCount, data : copy newData)
        }
    }

    getAt(index : 'i32)'char {
        data.getAt(index)
    }

    setAt(index : 'i32, item : 'char)'void {
        data.setAt(index, item)
    }

    isEqual(test : 'stack string) {
        data.isEqual(test.data)
    }

    isGreater(test : 'stack string)'bool {
        data.isGreater(test.data)
    }

    isGreaterOrEqual(test : 'stack string)'bool {
        data.isGreaterOrEqual(test.data)
    }

    isLess(test : 'stack string)'bool {
        data.isLess(test.data)
    }

    isLessOrEqual(test : 'stack string)'bool {
        data.isLessOrEqual(test.data)
    }

    toUpperCase()'string {
        a : array!char(datasize : ((count - 1) / 256 + 1) * 256)
        for i : 0 to count {
            a.initAt(i, data[i].toUpperCase())
        }
        string(count : count, data : copy a)
    }

    nullTerminate() {
        if !data.isGlobal || !_isNullTerminated {
            if count + 1 > data.dataSize {
                data = copy data.grow(count + 1)
            }
            data.initAt(count, '\0')
            _isNullTerminated = true
        }
        void
    }

    hash()'u32 {
        --c--
        #return(u32, kh_str_hash_func((char*)_parent->data.data));
        --c--
    }
) { this }

