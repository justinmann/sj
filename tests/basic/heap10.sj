inner() { this }

class(
	inner : inner()
) { this }

class2(
	inner : value(inner())
) { this }

x1'stack class : class()
x2'heap class : class()
// x3'stack class? : value(class()) // invalid, option must be heap
x4'heap class? : value(class())
x5'stack class2 : class2()
x6'heap class2 : class2()
// x7'stack class2? : value(class2()) // invalid, option must be heap
x8'heap class2? : value(class2())
