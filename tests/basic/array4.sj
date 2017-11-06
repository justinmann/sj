include "../../lib/common/array.sj"

class(x: 0) { this }
a : array!class(1)
a.set(0, class(1))
b : a.get(0)
c : b.x
a.delete(1)
c