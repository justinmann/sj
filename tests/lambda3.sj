
class(x : 12) { this }

func(cb : 'heap ()i32) {
	cb()
}

do() {
	c : class()
	a : func(heap ^() { c.x })
	debug.writeLine(a.asString())
}

do()