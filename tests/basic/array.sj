@hasThis
array't (
	count = 0
	_size = 0
	_data = (ptr)0

	@hasParent
	get(index : 'int)'heap t c{
		if (index >= count || index < 0) {
			exit(-1);
		}

		##t* p = _parent->data;
		return p[index];
	}c

	@hasParent
	set(index : 'int, item : 'heap t)'void c{
		if (index >= count || index < 0) {
			exit(-1);
		}

		##t* p = _parent->data;
		p[index] = (##t)item;
	}c

	@hasParent
	find(item : 'heap t)'int c{	
		##t* p = _parent->data;
		for (int index = 0; index < count; i++) {
			if (p[index] == item) {
				return index;
			}
		}
		return -1;
	}c
) c{ 
	if (count > 0) {
		malloc(count * sizeof(##t))
	}
	return _this; 
}c destroy c{
	if (_this->sjv_data != 0) { 
		free(_this->sjv_data);
	}
}c

class(
	bob : 1
) {
	this
}

a : array'class()
a.set(0, class(bob : 1))
a.set(1, class(bob : 2))