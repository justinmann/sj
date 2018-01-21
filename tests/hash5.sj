
class(
    x : 1
) { this }

a : hash![i32, weak class]()
c := heap class(1)
a[0] = c
debug.writeLine((a[0]?.x?:-1).asString())
c = heap class(2)
debug.writeLine((a[0]?.x?:-1).asString())