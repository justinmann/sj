include "array.sj"

list!t (
	count := 0
	data := array!t(0)

	add(item :'t) {
		if count > data.size {
			setSize(data.size * 2)
			void
		}

		data.setAt(count, item)
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
) { this }