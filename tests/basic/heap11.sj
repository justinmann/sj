inner() { this }

class(
	inner : inner()
) { this }

class2(
	inner : value(inner())
) { this }

x3'stack class? : value(class()) // invalid, option must be heap
x7'stack class2? : value(class2()) // invalid, option must be heap
