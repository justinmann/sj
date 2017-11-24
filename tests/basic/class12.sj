class(
	foo(x: 'i32)'i32 {
		if x > 0 {
			bar(x - 1)
		} else {
			0
		}
	}
	bar(x: 0) {
		foo(x)
	}
) { this }
c: class()
c.foo(4)