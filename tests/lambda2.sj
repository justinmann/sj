
class(x : 12) { this }

func(cb : '()i32) {
	cb()
}

do() {
	c : class()
	a : func(^() { c.x })
	debug.writeLine(a.asString())
}

do()