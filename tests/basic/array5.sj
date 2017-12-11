include "lib/common/common.sj"

class(x : 'i32) { this }
a : [class(1), class(2), class(3)]
c : local a[0]
c.x