include "common.sj"

#foo(
    test()'list!char
)

class #foo (
    test() {
        "5"
    }
) { this }

a: class() as #foo
a.test()