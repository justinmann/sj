package a {
	x : 0
	func() { x }
	#foo(
		bar()'i32
	)
	class #foo (
		bar() { func() }
	) { this }
}

package b {
	x : 1
	d : 12
	func() { x }
	#foo(
		bar()'i32
	)
	class #foo (
		bar() { func() }
	) { this }
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

e : a.class() as a.#foo
f : e.bar()

h : b.class() as b.#foo
i : h.bar()