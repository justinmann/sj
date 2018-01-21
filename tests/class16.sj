a(
    x: 1
    b: aa(
        c() { x }
    ) { this }
) { this }
a: a()
a.b.c()
d: a.b
d.c()