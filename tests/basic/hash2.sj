include "lib/common/common.sj"

a : hash![string, string]()
a["foo"] = "hi"
b : a["foo"]
debug.writeLine(b?:"not found")