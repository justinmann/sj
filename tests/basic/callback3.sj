include "lib/common/common.sj"

doMath(cb : 'heap (:i32)void) {
    cb(1)
    cb(2)
    void
}

@heap
class(
    total := 0

    func(x : 'i32) {
        total += x
        void
    }

    run() {
        doMath(cb : parent.func)
        total
    }
) { this }

c : heap class()
c.run()
