call(cb : '()i32) {
    cb()
}

class(
    x : 12

    func() {
        call(^{
            x
        })
    }
) { this }

c : class()
debug.writeLine(c.func().asString())