foo(
    getBar() { bar() }
) { this }

bar() { this }

func(a : 'bar) {
    a
}

f : empty'foo
f2 : foo()
a : func(f?.bar())