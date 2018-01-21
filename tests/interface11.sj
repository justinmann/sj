
#foo(
    test()'i32
    isEqual(f:'#foo)'bool
)

class #foo (
    x : 'i32
    test() { x }
    isEqual(f:'#foo)'bool {
        test() == f.test()
    }
) { this }

c := heap class(1)
a : weak c as #foo
debug.writeLine((a?.test()?:-1).asString())

c = heap class(2)
debug.writeLine((a?.test()?:-1).asString())
