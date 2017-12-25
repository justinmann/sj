include "lib/common/common.sj"

class(x : 12) { this }

func(cb : '()i32) {
	cb()
}

do() {
	c := 12
	a : func(^() { c++ })
	debug.writeLine(c.asString())
}

do()