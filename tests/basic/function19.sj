func(x: 'i32)'i32 {
    if x > 0 {
        func(x - 1)
    } else {
        0
    }
}
func(4)
