func() {
    debug.writeLine("should not get here")
    true
}

if false && func() {
    debug.writeLine("should get here")
}

debug.writeLine("end")
