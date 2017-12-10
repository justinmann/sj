list!t (
	count := 0
	data := array!t(0)

	add(item :'t) {
		if count >= data.size {
			setSize(i32_max(10, data.size * 2))
			void
		}

		data.initAt(count, item)
		count++
	}

	setSize(size : 'i32) {
		data.grow(size)
	}

	getAt(index : 'i32)'t {
		data.getAt(index)
	}

	setAt(index : 'i32, item : 't)'void {
		data.setAt(index, item)
	}

	removeAt(index : 'i32)'void {
		--c--
		if (index < 0 || index >= _parent->count) {
			halt("removeAt: out of bounds %d:%d\n", index, _parent->count);
		}
		#type(t)* p = (#type(t)*)_parent->data.data;
		if (index != _parent->count - 1) {
			memcpy(p + index, p + index + 1, _parent->count - index - 1);
		}
		_parent->count--;
		--c--
	}
) { this }