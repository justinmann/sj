#foo(
    test(a : 'i32)'bar
)

bar() { this }

class #foo (
    test(a : 0) {
        bar()
    }
) { this }

a: class() as #foo
// b : a.test(1)
c'heap bar : a.test(1)