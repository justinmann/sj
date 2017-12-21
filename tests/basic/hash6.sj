include "lib/common/common.sj"

class(
	x : 1

	hash() { x as u32 }
	isEqual(c : 'class) { x == c.x }
) { this }

a : hash![weak class, i32]()
c := heap class(1)
a[c] = 1
debug.writeLine((a[c]?:-1).asString())
c = heap class(2)
debug.writeLine((a[c]?:-1).asString())