
class(
    x : 1
) { this }

func() {
    empty'class
}

test()'class? {
    if true {
        copy empty'class
    } else {
        copy valid(class(2))
    }
}

a : func()

b : ifValid a {
    a.x
} elseEmpty {
    0
}

c : test()