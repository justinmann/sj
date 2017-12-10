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
/*
h : empty'(:i32)i32
i : value(func)
j : getValue(i)
k : j(12)
*/

// store as stack
// store as local
// store as heap option
// store as stack option
// store as local option
// get callback from template function
// f : foo!i32


