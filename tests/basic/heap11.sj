inner() { this }

class(
	inner : inner()
) { this }

class2(
	inner : value(inner())
) { this }

x3'stack class? : value(class())
x7'stack class2? : value(class2())
