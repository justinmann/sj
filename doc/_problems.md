* list
* llvm inline optimization
* string
* heap alloc
* ref counting
* derived class
* map
* stream
* interface


		math: (
			sub(x: 0, y: 0) {
				x - y
			}
		) { this }
		class(
			foo(x: 0) {
				if x > 0 {
					bar(math.sub(x, 1))
				} else {
					0
				}
			}
			bar(x: 0) {
				foo(x)
			}
		)
		c: class()
		c.foo(4)


a : funcNew() // stack alloc classA, call funcNew
a = funcNew() // heap alloc classA, call funcNew
a : funcRef() // illegal
a = funcRef() // assignment




** long term issues
security for "scripting" version
Attributes on method/class that marks it as using io, at compile all derived classes and users of method are also tagged with this attribute.

