include "lib/common/common.sj"

doMath(cb : 'heap (:i32)void) {
	cb(1)
	cb(2)
	void
}

class(
	total := 0

	func(x : 'i32) {
		total += x
		void
	}

	run() {
		doMath(cb : heap parent.func)
		total
	}
) { this }

c : heap class()
c.run()
