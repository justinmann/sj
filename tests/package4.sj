package foo {
    foo(
        do1()'bar { 
            a : bar() 
            a
        }
    ) { this }

    bar() { this }
}

f'foo.foo : foo.foo()
f.do1()