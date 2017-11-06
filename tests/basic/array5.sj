include "../../lib/common/array.sj"

a : array!int(1)
a.set(0, 1)
c : a.get(0)
a.delete(1)
c