include "lib/common/common.sj"

class(
	x : 'i32
	toString() { x.toString() }
) { this }

c := heap class(1)
d := heap class(2)
a : [weak c, weak d]

debug.writeLine(a.toString())

c = heap class(3)

debug.writeLine(a.toString())

d = heap class(4)

debug.writeLine(a.toString())
