include "lib/common/common.sj"

a : hash![i32, i32]()
a[1] = 2
b : a[1]
c : b?.asString()
debug.writeLine(c?:"not found")