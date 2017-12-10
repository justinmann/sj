include "../../lib/common/common.sj"

class!t(
	item1 : 't
	item2 : 't
	each(cb : 'heap (:t)void) {
		cb(item1)
		cb(item2)
	}
) { this }

sum(
	total := 0

	invoke(a : 'i32) {
		total += a
		void
	}
) { this }

s : heap sum()

c : class!i32(3, 4)
c.each(s.invoke)

a : [1, 2]
a.each(s.invoke)
