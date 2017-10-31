func(x: 'int)'int {
    if x > 0 {
        func(x - 1)
    } else {
        0
    }
}
func(4)
