math(
	sub(x: 'int, y: 'int) {
		x - y
	}
) { this }
class(
	m: math()
	foo(x: 0) {
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