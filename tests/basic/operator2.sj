class![t,j](
    x : 't
) { this }

`i32_addclass![i32, char]`(x : 'i32, y : 'class![i32, char]) {
    x + y.x
}

a : `i32_addclass![i32, char]`(1, class![i32, char](2))
b : 1 + class![i32, char](2)