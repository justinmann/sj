test(
    x : 0

    getAt(x : 'i32) {
        valid(test(x))
    }
) { this }

a : test.getAt(0)?.getAt(1)
b : test[0][1]