class(x : 1) { this }
func(c : 'class?) {
	c?.x?:0
}

c : value(class())
d : c?.x?:0
e : copy c?:class(2)
func(c)