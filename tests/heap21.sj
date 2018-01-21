
func!t(a : 'bool)'t? {
    s : "hi"    
    if a {
        valid(optionalCopy s)
    } else {
        empty't
    }
}

a : heap func!string(true)
b : heap func!string(false)