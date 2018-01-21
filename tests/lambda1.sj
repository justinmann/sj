
func(cb : '()i32) {
	cb()
}

a : func(cb : ^() { 12 })

debug.writeLine(a.asString())