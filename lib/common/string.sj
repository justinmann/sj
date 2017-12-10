include "array.sj"

string(
	count := 0
	data := array!char()

	add(item :'stack string) {
		if item.count > 0 {
			if count + item.count + 1 > data.size {
				data.grow(count + item.count + 1)
				void
			}

			for i (0 to item.count) {
				data.setAt(count, item.getAt(i))
				count++		
			}

			data.setAt(count, 0 as char)
		}
		parent
	}

	getAt(index : 'i32)'char {
		data.getAt(index)
	}

	setAt(index : 'i32, item : 'char)'void {
		data.setAt(index, item)
	}

	isEqual(test : 'stack string) {
		data.isEqual(test.data)
	}

	isGreater(test : 'stack string)'bool {
		data.isGreater(test.data)
	}

	isGreaterOrEqual(test : 'stack string)'bool {
		data.isGreaterOrEqual(test.data)
	}

	isLess(test : 'stack string)'bool {
		data.isLess(test.data)
	}

	isLessOrEqual(test : 'stack string)'bool {
		data.isLessOrEqual(test.data)
	}
) { this }