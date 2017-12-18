include "lib/common/common.sj"

#interface(
	bob()'string
)

class #interface(
	bob() { "bob" }
) { this }

a : hash![string, #interface]()
a["foo"] = class() as #interface
b : a["foo"]
debug.writeLine(b?.bob()?:"not found")