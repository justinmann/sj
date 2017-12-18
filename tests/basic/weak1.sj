include "lib/common/common.sj"

class() { this }

c := heap class()
d : weak c
e := weak c

debug.writeLine(isEmpty(d).toString())
debug.writeLine(isEmpty(e).toString())

e = empty'weak class

debug.writeLine(isEmpty(d).toString())
debug.writeLine(isEmpty(e).toString())

c = heap class()

debug.writeLine(isEmpty(d).toString())
debug.writeLine(isEmpty(e).toString())
