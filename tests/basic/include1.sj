include "../../lib/common/array.sj"

class(
	bob : 1
) {
	this
}

a : array!class(size := 2)
a.setAt(0, class(bob : 1))