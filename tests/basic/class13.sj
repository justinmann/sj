math(
	sub(x: 'i32, y: 'i32) {
		x - y
	}
) { this }
class(
	m: math()
	foo(x: 0)'i32 {
		if x > 0 {
			bar(m.sub(x, 1))
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