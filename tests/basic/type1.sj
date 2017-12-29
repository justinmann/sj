#iface()
class #iface(
	b() { 0 }
) { this }

a : class()
i : a as #iface

t1 : a.type
t2 : 5.type
t3 : a.b.type
t4 : i.type
t5 : i.classType
d1 : type(i32)
d2 : type(class)
d3 : type(()i32)
d4 : type(#iface)

debug.writeLine(t1.asString())
debug.writeLine(t2.asString())
debug.writeLine(t3.asString())
debug.writeLine(t4.asString())
debug.writeLine(t5.asString())
debug.writeLine(d1.asString())
debug.writeLine(d2.asString())
debug.writeLine(d3.asString())
debug.writeLine(d4.asString())