class() { this }

foo1() {
    class() // okay
}

foo2() {
    value(class()) // fail, auto is not compatible with option
}

x1 : foo1()
x2 : foo2()