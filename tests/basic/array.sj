array!t (
	count = 0
	_size = 0
	_data = 0 as ptr

	get(index : 'i32)'t c{
		#forceParent

		if (index >= count || index < 0) {
			exit(-1);
		}

		#type(t)* p = _parent->data;
		#type(t) val = p[index];
		if (!#isValue(t)) {
			if (val == 0) {
				exit(-1);
			}
		}
		return val;		
	}c

	set(index : 'i32, item : 't)'void c{
		#forceParent
		#forceHeap(item)

		if (index >= count || index < 0) {
			exit(-1);
		}

		#type(t)* p = _parent->data;
		#release(t)(p[index]);
		#retain(t)(item);
		p[index] = item;
	}c

	find(item : 't)'i32 c{	
		#forceParent

		#type(t)* p = _parent->data;
		for (int index = 0; index < count; i++) {
			if (p[index] == item) {
				return index;
			}
		}
		return -1;
	}c

	getSize() { _size }

	setSize(x : 'i32) c{
		#forceParent

		if (x < 0) {
			exit(-1);
		}

		if (_size != x) {
			if (x != 0) {
				if (_parent->_data == 0) {
					_parent->_data = malloc(x * sizeof(#type(t)));
				} else {
					_parent->_data = realloc(x * sizeof(#type(t)));
				}
			}
			_size = x;
		}
	}c
) { 
	setSize(count)
	this 
} destroy c{
	free((#type(t)*)_this->_data);	
}c

class(
	bob : 1
) {
	this
}

a : array!class(count = 2)
a.set(0, class(bob : 1))
a.set(1, class(bob : 2))