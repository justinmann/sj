array!t (
	dataSize := 0
	data := 0 as ptr
	_isGlobal := false
	count := 0

	getAt(index : 'i32)'t --c--
		if (index >= _parent->count || index < 0) {
			halt("getAt: out of bounds\n");
		}

		#type(t)* p = (#type(t)*)_parent->data;
		#return(t, p[index]);		
	--c--
	

	initAt(index : 'i32, item : 't)'void {
		--c--
		if (index != _parent->count) {
			halt("initAt: can only initialize last element\n");		
		}
		if (index >= _parent->dataSize || index < 0) {
			halt("initAt: out of bounds %d:%d\n", index, _parent->dataSize);
		}

		#type(t)* p = (#type(t)*)_parent->data;
		#retain(t, p[index], item);
		_parent->count = index + 1;
		--c--
	}

	setAt(index : 'i32, item : 't)'void {
		--c--
		if (index >= _parent->count || index < 0) {
			halt("setAt: out of bounds %d:%d\n", index, _parent->count);
		}

		#type(t)* p = (#type(t)*)_parent->data;
		#release(t, p[index]);
		#retain(t, p[index], item);
		--c--
	}

	find(item : 't)'i32 {
		match = -1
		--c--	
		#type(t)* p = (#type(t)*)_parent->data;
		for (int index = 0; index < _parent->count; i++) {
			if (p[index] == item) {
				match = index;
			}
		}
		--c--
		match
	}

	each(cb : '(:t)void)'void {
		for i : 0 to count {
			cb(getAt(i))
		}
	}

	map!new_t(cb : '(:t)new_t)'array!new_t {
		newData := 0 as ptr
		--c--
		sjv_newData = (uintptr_t)malloc(_parent->count * sizeof(#type(new_t)));
		--c--
		for i : 0 to count {
			newItem : cb(getAt(i))
			--c--
			#type(new_t)* p = (#type(new_t)*)sjv_newData;
			#retain(new_t, p[i], newItem);
			--c--
		}		
		array!new_t(data: newData, dataSize: count, count: count)
	}

	filter(cb : '(:t)bool)'array!t {
		newData := 0 as ptr
		newCount := 0
		--c--
		sjv_newData = (uintptr_t)malloc(_parent->count * sizeof(#type(t)));
		--c--
		for i : 0 to count {
			item : getAt(i)
			if (cb(item)) {
				--c--
				#type(t)* p = (#type(t)*)sjv_newData;
				#retain(t, p[sjv_newCount], item);
				--c--
				newCount++
			}
		}		
		array!t(data: newData, dataSize: count, count: newCount)
	}

	foldl!result(initial : 'result, cb : '(:result, :t)result)'result {
		r := initial
		for i : 0 to count {
			r = cb(r, getAt(i))
		}			
		r
	}

	foldr!result(initial : 'result, cb : '(:result, :t)result)'result {
		r := initial
		for i : 0 toReverse count {
			r = cb(r, getAt(i))
		}			
		r
	}

	grow(new_size :' i32)'void {
		--c--
		if (_parent->dataSize != new_size) {
			if (new_size < _parent->dataSize) {
				halt("grow: new size smaller than old _parent->dataSize %d:%d\n", new_size, _parent->dataSize);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				#type(t)* p = (#type(t)*)_parent->data;
				_parent->data = (uintptr_t)malloc(new_size * sizeof(#type(t)));
				if (!_parent->data) {
					halt("grow: out of memory\n");
				}
				memcpy((void*)_parent->data, p, _parent->dataSize * sizeof(#type(t)));
			} else {
				_parent->data = (uintptr_t)realloc((void*)_parent->data, new_size * sizeof(#type(t)));
				if (!_parent->data) {
					halt("grow: out of memory\n");
				}
				memset((#type(t)*)_parent->data + _parent->dataSize, 0, (new_size - _parent->dataSize) * sizeof(#type(t)));
			}
			_parent->dataSize = new_size;
		}
		--c--
		void
	} 

	_quickSort(left : 'i32, right : 'i32) {
		i := left
		j := right

		pivot : getAt((left + right) / 2)
		while i <= j {
			while getAt(i) < pivot {
				i++
			}

			while getAt(j) > pivot {
				j--
			}

			if i <= j {
				tmp : getAt(i)
				setAt(i, getAt(j))
				setAt(j, tmp)
				i++
				j--
			}
		}

		if left < j {
			_quickSort(left, j);
		}
		if i < right {
			_quickSort(i, right);
		}
	}

	_quickSortCallback(left : 'i32, right : 'i32, cb : '(:t, :t)i32) {
		i := left
		j := right

		pivot : getAt((left + right) / 2)
		while i <= j {
			while cb(getAt(i), pivot) < 0 {
				i++
			}

			while cb(getAt(j), pivot) > 0 {
				j--
			}

			if i <= j {
				tmp : getAt(i)
				setAt(i, getAt(j))
				setAt(j, tmp)
				i++
				j--
			}
		}

		if left < j {
			_quickSortCallback(left, j, cb);
		}
		if i < right {
			_quickSortCallback(i, right, cb);
		}
	}

	sort() {
		_quickSort(0, count - 1)
	}

	sortcb(cb : '(:t, :t)i32) {
		_quickSortCallback(0, count - 1, cb)
	}

	reverse() {
		for i : 0 to count / 2 {
			j : count - i - 1
			tmp : getAt(i)
			setAt(i, getAt(j))
			setAt(j, tmp)
		}
	}

	toString(sep : ", ") {
		result := ""
		for i : 0 to count {
			if i != 0 {
				result = copy result + sep
			}
			result = copy result + getAt(i).toString()
		}
		copy result
	}

	isEqual(test :' array!t)'bool --c--
		if (_parent->count != test->count) {
			*_return = false;
		}

		*_return = memcmp((void*)_parent->data, (void*)test->data, _parent->count * sizeof(#type(t))) == 0;		
	--c--

	isGreater(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->count < test->count ? _parent->count : test->count) * sizeof(#type(t))) > 0;		
	--c--

	isGreaterOrEqual(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->count < test->count ? _parent->count : test->count) * sizeof(#type(t))) >= 0;		
	--c--

	isLess(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->count < test->count ? _parent->count : test->count) * sizeof(#type(t))) < 0;		
	--c--

	isLessOrEqual(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->count < test->count ? _parent->count : test->count) * sizeof(#type(t))) <= 0;		
	--c--
) {
	--c--
	if (_this->dataSize < 0) {
		halt("size is less than zero");
	}

	if (!_this->data) {
		_this->data = (uintptr_t)malloc(_this->dataSize * sizeof(#type(t)));
		if (!_this->data) {
			halt("grow: out of memory\n");
		}
	}
	--c--
	this
} copy {
	--c--
	_this->data = _from->data;
	if (!_this->_isGlobal && _this->data) {
		_retain((void*)_this->data);
	}
	--c--
} destroy {
	--c--
	if (!_this->_isGlobal && _this->data) {
		if (_release((void*)_this->data)) {
			free((#type(t)*)_this->data);
		}
	}
	--c--
}
