
#foo(
    test()'i32
)

class #foo (
    test() {
        debug.writeLine("test")
        5
    }
) { this }

a: class() as #foo
a.test()