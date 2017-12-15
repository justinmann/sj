package a {
	x : 0
	func() { x }
}

import a, b {
	b : x
	c : func()
}

import 
	a.b
	b.c.d
	c.d.e.f
{
	x : 0
}