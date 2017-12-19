include "lib/common/common.sj"

#foo(
    test()'i32
)

class #foo (
    test() {
        5
    }
) { this }

a: class() as #foo
a.test()