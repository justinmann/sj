emptyStringData := nullptr
--c--
sjv_emptystringdata = "";
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
		if item.count == 0 {
			string(count : count, data : copy data)			
		} else {
			newData : data.grow(count + item.count + 1)
			newCount := count
			newData.setAt(newCount, item.getAt(0))
			newCount++

			for i : 1 to item.count {
				newData.initAt(newCount, item.getAt(i))
				newCount++		
			}

			newData.initAt(newCount, 0 as char)
			string(count : newCount, data : copy newData)
		}
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
