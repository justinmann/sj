class() { this }

func(v : 'bool) {
    if v {
        c : matchReturn class()
        valid(c)
    } else {
        empty'class
    }
}

a : func(true)
b : func(false)
c : heap func(true)
d : heap func(false)