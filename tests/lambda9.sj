class(x := 12) { this }

func(cb : 'heap ()i32) {
	cb()
}

do() {
	c : class()
	a : ^() { c.x++ }
	f : a()
	b : a
	debug.writeLine(f.asString())
}

do()