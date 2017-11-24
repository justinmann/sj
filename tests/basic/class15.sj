math: ^(
    test: 1
    sub(x: 'i32, y: 'i32) {
		x - y - test
	}
) { this }

class(
	foo(x: 0)'i32 {
		if x > 0 {
			bar(math.sub(x, 1))
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