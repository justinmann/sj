// @hasThis
array!t (
	count = 0
	_size = 0
	_data = 0 as ptr

//	@hasParent
	get(index : 'i32)'t c{
		if (index >= count || index < 0) {
			exit(-1);
		}

		#t#* p = _parent->data;
		#t# val = p[index];
		return val;		
	}c

//	@hasParent
	set(index : 'i32, item : 't)'void c{
		if (index >= count || index < 0) {
			exit(-1);
		}

		#t#* p = _parent->data;
		#t#_release(p[index]);
		#t#_retain(item);
		p[index] = item;
	}c

//	@hasParent
	find(item : 't)'i32 c{	
		##t* p = _parent->data;
		for (int index = 0; index < count; i++) {
			if (p[index] == item) {
				return index;
			}
		}
		return -1;
	}c

	getSize() { _size }

//	@hasParent
	setSize(x : 'i32) c{
		if (x < 0) {
			exit(-1);
		}

		if (_size != x) {
			if (x != 0) {
				if (_parent->_data == 0) {
					_parent->_data = malloc(x * sizeof(##t));
				} else {
					_parent->_data = realloc(x * sizeof(##t));
				}
			}
			_size = x;
		}
	}c
) { 
	setSize(count)
	this 
}

class(
	bob : 1
) {
	this
}

a : array!class(count = 2)
a.set(0, class(bob : 1))
a.set(1, class(bob : 2))