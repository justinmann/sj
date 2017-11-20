inner() { this }

class(
	inner : inner()
) { this }

class2(
	inner : value(inner())
) { this }

x1'stack class : class()
x2'heap class : class()
x4'heap class? : value(class())
x5'stack class2 : class2()
x6'heap class2 : class2()
x8'heap class2? : value(class2())
