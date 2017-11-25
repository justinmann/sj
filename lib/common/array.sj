array!t (
	size = 0
	data = 0 as ptr
	_isGlobal = false

	getAt(index : 'i32)'t c{
		int32_t size;
		#retain(i32, size, size);
		uintptr_t data;
		#retain(ptr, data, data);

		if (index >= size || index < 0) {
			printf("getAt: out of bounds\n");
			exit(-1);
		}

		#type(t)* p = (#type(t)*)data;
		#return(t, p[index]);		
	}c

	initAt(index : 'i32, item : 't)'void c{
		int32_t size;
		#retain(i32, size, size);
		uintptr_t data;
		#retain(ptr, data, data);

		if (index >= size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, size);
			exit(-1);
		}

		#type(t)* p = (#type(t)*)data;
		#retain(t, p[index], item);
	}c

	setAt(index : 'i32, item : 't)'void c{
		int32_t size;
		#retain(i32, size, size);
		uintptr_t data;
		#retain(ptr, data, data);

		if (index >= size || index < 0) {
			printf("setAt: out of bounds %d:%d\n", index, size);
			exit(-1);
		}

		#type(t)* p = (#type(t)*)data;
		#release(t, p[index]);
		#retain(t, p[index], item);
	}c

	find(item : 't)'i32 c{	
		int32_t size;
		#retain(i32, size, size);
		uintptr_t data;
		#retain(ptr, data, data);

		#type(t)* p = (#type(t)*)data;
		for (int index = 0; index < size; i++) {
			if (p[index] == item) {
				*_return = index;
			}
		}
		*_return =  -1;
	}c

	grow(newSize :' i32)'void c{
		#include(<string.h>)

		int32_t size;
		#retain(i32, size, size);
		uintptr_t data;
		#retain(ptr, data, data);

		if (size != newSize) {
			if (newSize < size) {
				printf("grow: new size smaller than old size %d:%d\n", newSize, size);
				exit(-1);
			}
			
			if (_parent->_isGlobal) {
				_parent->_isGlobal = false;
				#type(t)* p = (#type(t)*)data;
				data = (uintptr_t)calloc(newSize * sizeof(#type(t)), 1);
				if (!data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memcpy((void*)data, p, size * sizeof(#type(t)));
			} else {
				data = (uintptr_t)realloc((void*)data, newSize * sizeof(#type(t)));
				if (!data) {
					printf("grow: out of memory\n");
					exit(-1);				
				}
				memset((#type(t)*)data + size, 0, (newSize - size) * sizeof(#type(t)));
			}
			size = newSize;
		}
	}c 

	isEqual(test :' array!t)'bool c{
		#include(<string.h>)

		if (size != test->size) {
			*_return = false;
		}

		*_return = memcmp((void*)data, (void*)test->data, size * sizeof(#type(t))) == 0;		
	}c

	isGreater(test :' array!t)'bool c{
		#include(<string.h>)

		*_return = memcmp((void*)data, (void*)test->data, (size < test->size ? size : test->size) * sizeof(#type(t))) > 0;		
	}c

	isGreaterOrEqual(test :' array!t)'bool c{
		#include(<string.h>)

		*_return = memcmp((void*)data, (void*)test->data, (size < test->size ? size : test->size) * sizeof(#type(t))) >= 0;		
	}c

	isLess(test :' array!t)'bool c{
		#include(<string.h>)

		*_return = memcmp((void*)data, (void*)test->data, (size < test->size ? size : test->size) * sizeof(#type(t))) < 0;		
	}c

	isLessOrEqual(test :' array!t)'bool c{
		#include(<string.h>)

		*_return = memcmp((void*)data, (void*)test->data, (size < test->size ? size : test->size) * sizeof(#type(t))) <= 0;		
	}c
) {
	c{
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
	}c
	this
} destroy c{
	if (!_this->_isGlobal && _this->data) {
		free((#type(t)*)_this->data);
		_this->data = 0;	
	}
}c
