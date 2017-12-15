package a {
	x : 0
}

package b {
	func() { a.x }	
}

import z : a, b {
	b : z.x
	c : func()
}

import 
	a.b
	b.c.d
	c.d.e.f
{
	y : 0
}