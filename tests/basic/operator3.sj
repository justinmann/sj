#foo(
    getX()'i32
)

class #foo (
    x : 'i32
    getX() { x }
) { this }

`i32_add#foo`(x : 'i32, y : '#foo) {
    x + y.getX()
}

a : `i32_add#foo`(1, class(2) as #foo)
b : 1 + class(2) as #foo