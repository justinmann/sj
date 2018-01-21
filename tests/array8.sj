
#foo(
    getBar()'i32
    setBar(x : 'i32)'void
)

class #foo (
    bar := 0
    getBar() { bar }
    setBar(x : 'i32) { bar = x; void } 
) { this }

a : [class() as #foo]
b : a[0]