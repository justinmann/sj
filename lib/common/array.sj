array!t (
	size = 0
	_data = 0 as ptr

	getAt(index : 'i32)'t c{
		#forceParent()

		if (index >= count || index < 0) {
			exit(-1);
		}

		#type(t)* p = (#type(t)*)_parent->_data;
		#type(t) val = p[index];
		if (!#isValue(t)) {
			if (val == 0) {
				exit(-1);
			}
		}
		return val;		
	}c

	setAt(index : 'i32, item : 't)'void c{
		#forceParent()
		#forceHeap(item)

		if (index >= _parent->count || index < 0) {
			exit(-1);
		}

		#type(t)* p = (#type(t)*)_parent->_data;
		#release(t, p[index]);
		#retain(t, item);
		p[index] = item;
	}c

	find(item : 't)'i32 c{	
		#forceParent()

		#type(t)* p = (#type(t)*)_parent->_data;
		for (int index = 0; index < count; i++) {
			if (p[index] == item) {
				return index;
			}
		}
		return -1;
	}c
) {
	c{
		if (_this->size < 0) {
			exit(-1);
		}

		_this->_data = (uintptr_t)malloc(_this->size * sizeof(#type(t)));
	}c
	this
} destroy c{
	free((#type(t)*)_this->_data);	
}c
