array!t (
	size = 0
	data = 0 as ptr
	_isGlobal = false

	getAt(index : 'i32)'t --c--
		if (index >= _parent->size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		#type(t)* p = (#type(t)*)_parent->data;
		#return(t, p[index]);		
	--c--
	

	initAt(index : 'i32, item : 't)'void {
		--c--
		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
		}

		#type(t)* p = (#type(t)*)_parent->data;
		#retain(t, p[index], item);
		--c--
	}

	setAt(index : 'i32, item : 't)'void {
		--c--
		if (index >= _parent->size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, _parent->size);
			exit(-1);
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
		for (int index = 0; index < _parent->size; i++) {
			if (p[index] == item) {
				match = index;
			}
		}
		--c--
		match
	}

	grow(new_size :' i32)'void {
		--c--
		if (_parent->size != new_size) {
			if (new_size < _parent->size) {
				printf("grow: new _parent->size smaller than old _parent->size %d:%d\n", new_size, _parent->size);
				exit(-1);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				#type(t)* p = (#type(t)*)_parent->data;
				_parent->data = (uintptr_t)calloc(new_size * sizeof(#type(t)), 1);
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memcpy((void*)_parent->data, p, _parent->size * sizeof(#type(t)));
			} else {
				_parent->data = (uintptr_t)realloc((void*)_parent->data, new_size * sizeof(#type(t)));
				if (!_parent->data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memset((#type(t)*)_parent->data + _parent->size, 0, (new_size - _parent->size) * sizeof(#type(t)));
			}
			_parent->size = new_size;
		}
		--c--
		void
	} 

	isEqual(test :' array!t)'bool --c--
		if (_parent->size != test->size) {
			*_return = false;
		}

		*_return = memcmp((void*)_parent->data, (void*)test->data, _parent->size * sizeof(#type(t))) == 0;		
	--c--

	isGreater(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->size < test->size ? _parent->size : test->size) * sizeof(#type(t))) > 0;		
	--c--

	isGreaterOrEqual(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->size < test->size ? _parent->size : test->size) * sizeof(#type(t))) >= 0;		
	--c--

	isLess(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->size < test->size ? _parent->size : test->size) * sizeof(#type(t))) < 0;		
	--c--

	isLessOrEqual(test :' array!t)'bool --c--
		*_return = memcmp((void*)_parent->data, (void*)test->data, (_parent->size < test->size ? _parent->size : test->size) * sizeof(#type(t))) <= 0;		
	--c--
) {
	--c--
	#include(<string.h>)

	if (_this->size < 0) {
		exit(-1);
	}

	if (_this->data) {
		_this->_isGlobal = true;
	} else {
		_this->data = (uintptr_t)calloc(_this->size * sizeof(#type(t)), 1);
		if (!_this->data) {
			printf("grow: out of memory\n");
			exit(-1);				
		}
	}
	--c--
	this
} destroy {
	--c--
	if (!_this->_isGlobal && _this->data) {
		free((#type(t)*)_this->data);
		_this->data = 0;	
	}
	--c--
}
