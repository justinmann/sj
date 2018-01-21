test(
    x : 0

    getAt(x : 'i32) {
        valid(test(x))
    }
) { this }

t : test()
a : t.getAt(0)?.getAt(1)
b : t[0][1]