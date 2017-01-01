array<t> (
	add(block'():t) {

	}

	map([outer] block'(t)) {
		newList : array<t>(length : length)

		for(0, length) {
			newList.set(_, block(items[_]))
		}

		newList
	}

	each([outer] block'(t)) {
		for(0, length) {
			block(items[_])
		}
	}

	findAndRun<j>(check : required#(t)bool, run : required#(t)j, default : required#()j) : j {	
		beginloop(counter, end - start)
		gotoifnot(block(items[counter]), continue) 
		exit(run(items[counter]))
@continue
		block(counter + start)	
		endloop(counter)
		exit(default())
	}
)