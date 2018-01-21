#iface(
	func1()'heap class2
	func2()'heap class2?
)

class2() { this }

class #iface(
	func1() {
		heap class2()
	}

	func2() {
		empty'heap class2
	}
) { this }

i : heap class() as #iface
c1 : i.func1()
c2 : i.func2()