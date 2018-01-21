
class(
    x : 'i32

    isLess(c : 'class) {
        x < c.x
    }

    isGreater(c : 'class) {
        x > c.x
    }

    asString() {
        "c" + i32_asString(x)
    }
) { this }

class_compare(l : 'class, r : 'class) {
    i32_compare(l.x, r.x)
}


a : [class(1), class(4), class(5), class(6), class(2)]
a.sort()
console.writeLine(a.asString())

a.reverse()
console.writeLine(a.asString())

a.sortcb(class_compare)
console.writeLine(a.asString())
