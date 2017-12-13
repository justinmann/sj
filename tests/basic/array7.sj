include "lib/common/common.sj"


class(
	x : 'i32

	isLess(c : 'class) {
		x < c.x
	}

	isGreater(c : 'class) {
		x > c.x
	}

	toString() {
		copy "c" + i32_toString(x)
	}
) { this }


a : [class(1), class(4), class(5), class(6), class(2)]
a.sort()
console.writeLine(a.toString())

a.reverse()
console.writeLine(a.toString())

a.sort()
console.writeLine(a.toString())
