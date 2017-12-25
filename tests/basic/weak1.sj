
class() { this }

c := heap class()
d : weak c
e := weak c

debug.writeLine(isEmpty(d).asString())
debug.writeLine(isEmpty(e).asString())

e = empty'weak class

debug.writeLine(isEmpty(d).asString())
debug.writeLine(isEmpty(e).asString())

c = heap class()

debug.writeLine(isEmpty(d).asString())
debug.writeLine(isEmpty(e).asString())
