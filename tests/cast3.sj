#iface(
    getX()'i32
)

bob #iface(
    getX() { 13 }
) { this }

class(
    asString() { "hello" }
    asI32() { 12 }
    `asArray!i32`() { [ 12 ] }
    `as#iface`() { bob() as #iface }
) { this }

c : class()
debug.writeLine(c as string)
debug.writeLine(12 as string)
debug.writeLine((c as i32).asstring())
debug.writeLine((c as array!i32)[0] as string)
debug.writeLine((c as #iface).getX() as string)