include "lib/common/common.sj"

class(x : 12) { this }

func(start : 'i32, cb : '(:i32)i32) {
	cb(start)
}

do() {
	c : 12
	a : func(11, ^{ c += _ })
	debug.writeLine(c.asString())
}

do()