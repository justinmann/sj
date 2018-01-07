class() { this }

func(v : 'bool) {
    if v {
        c : class()
        valid(optionalCopy c)
    } else {
        empty'class
    }
}

a : func(true)
b : func(false)
c : heap func(true)
d : heap func(false)