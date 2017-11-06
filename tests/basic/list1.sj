include "../../lib/common/list.sj"

class(x : 'int) { this }
a: list!class()
for x: 1 to 100000 {
    a.add(class(x))
}
c : a[0]
c.x