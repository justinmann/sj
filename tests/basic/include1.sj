include "lib/common/common.sj"

class(
    bob : 1
) {
    this
}

a : array!class(dataSize := 2)
a.initAt(0, class(bob : 1))