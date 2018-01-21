
class(
    d : empty'i32
) { this }

a : empty'i32
b : valid(5)
c : class()

w : ifValid a {
    a
} elseEmpty {
    2
}

x : ifValid b {
    b
} elseEmpty {
    2
}

y : ifValid c : c.d {
    c
} elseEmpty {
    1
}
