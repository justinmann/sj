* "parent"
* this. implicit parent lookup
* dot for function call

* list
* string
* heap alloc
* ref counting
* derived class
* map
* stream
* interface


* class
* function returning class
funcNew() {
	classA()
}

globalA : classA()
funcRef() {
	globalA
}

*********
a(
	x: 1
	b() { x }
) { this }

a: a()
a.b()
--
struct a_t {
	int x;
};
struct b_t {
	b_t parent;
};

a_t a(a_t& this) { return this; }
int b(b_t& this) { return this.parent.x; }

a_t = { 1 };
a = a(a_t);
b_t = { a };
b(b_t);
***********
a(
	x: 1
	b: (
		c() { x }
	) { this }
) { this }
a: a()
a.b.c()
d: a.b
d.c()
--
struct a_t {
	int x;
	b_t b;
};

struct b_t {
	a_t parent;
};

struct c_t {
	b_t parent;
};

a_t a(a_t& this) { return this; }
b_t b(b_t& this) { return this; }
int c(c_t& this) { return this.parent.parent.x; }

a_t = { x = 1, b = { parent = a_t } };
a = a(a_t);
c_t = { parent = a.b };
c(c_t);

d = a.b;
c_t = { parent = d };
c(c_t);
***********

a : funcNew() // stack alloc classA, call funcNew
a = funcNew() // heap alloc classA, call funcNew
a : funcRef() // illegal
a = funcRef() // assignment




** long term issues
security for "scripting" version
Attributes on method/class that marks it as using io, at compile all derived classes and users of method are also tagged with this attribute.

