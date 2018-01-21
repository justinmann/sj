
class(x := 12) { this }

func(cb : '()i32) {
	cb()
}

do() {
	c : class()
	a : func(^() { 
		c.x += 2
		func(^() {
			c.x += 2
		})
	})
	debug.writeLine(c.x.asString())
}

do()