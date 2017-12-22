class(
	x : 1
	_y : 2
	foo() { _func() + _y }
	_func() { x }
) { this }

c : class()
a : c.foo()