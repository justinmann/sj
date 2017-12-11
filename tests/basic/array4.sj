include "lib/common/common.sj"

class(x: 0) { this }
a : array!class(1)
a.setAt(0, class(1))
b : a.getAt(0)
c : b.x
c