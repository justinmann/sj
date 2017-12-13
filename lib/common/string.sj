emptyStringData := 0 as ptr
--c--
sjv_emptyStringData = (uintptr_t)"";
--c--

string(
	count := 0
	data := array!char(
		data : emptyStringData
		dataSize : 1
		count : 1
		_isGlobal : true
	)

	add(item : 'string) {
		if item.count > 0 {
			if count + item.count + 1 > data.dataSize {
				data.grow(count + item.count + 1)
				void
			}

			data.setAt(count, item.getAt(0))
			count++

			for i : 1 to item.count {
				data.initAt(count, item.getAt(i))
				count++		
			}

			data.initAt(count, 0 as char)
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