* required parameter
func(i:'int)

* work docs

* extern class
math.cos(4.0)

* template

class<t>(
	x:'t
	get() { x }
	set(a:'t) { x = a }
) { this }
c: class<int>()
c.set(c.get() + 1)

* extern array class
b: array<int>()
b.set(0)
b.get(0)

class(x: 0) { this }
b: array<class>(1)
b.set(class(5))
b.set(class(6))
b.get(0)
b.setSize(12)

* list
list<t>(
	count= 0
	
	add(element:'t) {
		if (b.size < count) {
			b.grow(count * 2)
		}
		b.set(count, element)
		count = count + 1 
	}
	
	get(index:'int) {
		b.get(index)
	}
) {
	b: array<t>()
}

* list syntax
* lambda
item(
	x: 0
)

l: list<item>()
l.add(item(1))
l.add(item(2))
l.each(^(i'item) { 
	i.x = i.x + 1
})
l[0].x

* string
* exceptions
* heap alloc
* ref counting
* map
* stream

** future
* llvm optimization
* derived class
* private var
* interface
* security for "scripting" version
* attributes on method/class that marks it as using io, at compile all derived classes and users of method are also tagged with this attribute.

