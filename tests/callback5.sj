
bob(x : 0) { this }

#foo(
    getBar()'bob
)

class #foo (
    bar := 0
    getBar() { bob(bar) }
) { this }

f : weak class() as #foo
cb : f?.getBar
ifValid cb {
    a : cb()
    b : heap cb()
}