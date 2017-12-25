
class(x : 12) { this }

func(start : 'i32, cb : '(:i32)i32) {
	cb(start)
}

do() {
	c : 12
	a : func(11, ^(y : 'i32) { c += y })
	debug.writeLine(c.asString())
}

do()