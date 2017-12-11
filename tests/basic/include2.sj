func() {
	include "lib/common/common.sj"
}

class(
	bob : 1
) {
	this
}

a : array!class(count := 2)
a.set(0, class(bob : 1))