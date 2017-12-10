data(
	x : 0
) { this }

class(
	b : 15
	func(a : 'i32)'data { 
		data(a + b)
	}
) { this }

func(a : 'i32)'data {
	data(a + 2)
}

func2![t](a : 'i32)'t {
	t(a + 2)
}

class2![t](
	b : 15
	func(a : 'i32)'t { 
		t(a + b)
	}
) { this }

getCallback()'heap (:i32)data {
	c : heap class()
	c.func
}

callback(f : '(:i32)data)'i32 {
	d : f(12)
	d.x
}

a : func
b : heap a(1)
l : getCallback()
m : l(1)
n : heap l(1)
c : class()
a2 : callback(func)
b2 : callback(c.func)
f1 : func
d : f1(1)
f2 : c.func
e : f2(2)
c_heap : heap class()
f3 : c_heap.func
g : f3(3)
h : empty'(:i32)data
i : value(func)
j : getValue(i)
k : j(12)
o : func2![data]
p : l(1)