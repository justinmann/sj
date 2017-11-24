class() { this }

foo1() {
    class() // okay
}

foo2() {
    value(heap class()) // value will force the class to be heap
}

x1 : foo1()
x2 : heap foo2()