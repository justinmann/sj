include "lib/common/common.sj"

#foo!item(
    test()'item
)

class #foo!i32 (
    test() {
        5
    }
) { this }

a: class() as #foo!i32
a.test()