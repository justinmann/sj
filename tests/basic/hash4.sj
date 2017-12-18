include "lib/common/common.sj"

#interface(
	bob()'i32
	hash()'u32
	isEqual(b : '#interface)'bool
)

class #interface(
	x : 0
	bob() { x }

	hash() { bob() as u32 }
	isEqual(b : '#interface) { bob() == b.bob() } 
) { this }

a : hash![#interface, i32]()
a[class(1) as #interface] = 1
b : a[class(1) as #interface]
debug.writeLine((b?:-1).toString())