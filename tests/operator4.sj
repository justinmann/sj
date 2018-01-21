
#foo(
    getBar()'i32
    setBar(x : 'i32)'void
)

class #foo (
    bar := 0
    getBar() { bar }
    setBar(x : 'i32) { bar = x; void } 
) { this }

f : class() as #foo
f.bar = f.bar + 1

debug.writeLine(f.bar.asString())