include "../../lib/common/common.sj"

#foo(
    test()'string
)

class #foo (
    test() {
        "5"
    }
) { this }

a: class() as #foo
a.test()