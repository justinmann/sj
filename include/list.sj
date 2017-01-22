list!t(
	space = 16
	count = 0
	items = array!t(16)
	
	add(element : 't) {
		if (count < space) {
			throw(0)
			/* space = count * 2
			items = items.grow(space) */
		}
		items.set(count, element)
		count = count + 1 
	}

	get(index : 'int) {
		if (index < 0 || index >= count) {
			throw(0)
		}
		items.get(index)
	}

	set(index : 'int, element : 't) {
		if (index < 0 || index >= count) {
			throw(0)
		}
		items.set(index, element)
	}
) { this }
