include "array.sj"

string (
	count = 0
	data = array!char()

	add(item :'string) {
		if count + item.count > data.size {
			data.grow(data.size + item.count)
			void
		}

		for i : 0 to item.count - 1 {
			data.setAt(count, item.getAt(i))
			count++		
		}

		data.setAt(count, 0 as char)
	}

	getAt(index : 'i32)'char {
		data.getAt(index)
	}

	setAt(index : 'i32, item : 'char)'void {
		data.setAt(index, item)
	}

	isEqual(test :' string) {
		data.isEqual(test.data)
	}

	isGreater(test :' string)'bool {
		data.isGreater(test.data)
	}

	isGreaterOrEqual(test :' string)'bool {
		data.isGreaterOrEqual(test.data)
	}

	isLess(test :'string)'bool {
		data.isLess(test.data)
	}

	isLessOrEqual(test :' string)'bool {
		data.isLessOrEqual(test.data)
	}
) { this }