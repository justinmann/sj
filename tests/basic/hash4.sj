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

a : hash![heap #interface, i32]()
a[heap class(32) as #interface] = 1
b : a[heap class(1) as #interface]

a.each(print)
debug.writeLine((b?:-1).asString())

print(k : '#interface, v : 'i32) {
	debug.writeLine(k.bob().asString() + " = " + v.asString())	
}