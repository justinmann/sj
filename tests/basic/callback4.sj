include "lib/common/common.sj"

class(
	run() {
		debug.writeLine("hello")
		value(1)
	}
) { this }

c := heap class()
d : weak c.run
result1 : d()
debug.writeLine((result1?:-1).toString())

c = heap class()
result2 : d()
debug.writeLine((result2?:-1).toString())
