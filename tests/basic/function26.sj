include "lib/common/common.sj"

@heap
func(
    bar() {
        parent
    }
) { this }

a'heap func : func()
b'heap func : a.bar()