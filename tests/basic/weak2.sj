
class(
    x : 'i32
    asString() { x.asString() }
) { this }

c := heap class(1)
d := heap class(2)
a : [weak c, weak d]

debug.writeLine(a.asString())

c = heap class(3)

debug.writeLine(a.asString())

d = heap class(4)

debug.writeLine(a.asString())
