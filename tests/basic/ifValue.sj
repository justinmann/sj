class(
	d : empty'i32
) { this }

a : empty'i32
b : value(5)
c : class()

w : ifValue a {
	a
} elseEmpty {
	2
}

x : ifValue b {
	b
} elseEmpty {
	2
}

y : ifValue c : c.d {
	c
} elseEmpty {
	1
}
