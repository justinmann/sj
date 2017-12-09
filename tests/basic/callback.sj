func()'void {
	x : 0
}

f : func
f()

/*
callback(f : '()void) {
	f()
}

callback(func)
*/
// verify arg types

/* return heap
foo() { this }

callback(f : '()heap foo) {
	foo : f()
}
*/

/* store as heap
foo() { class() }
f : heap foo 	// 'heap ()heap foo
f : stack foo  	// 'heap ()stack foo
f : foo 		// 'heap ()stack foo

class(
	func() { 0 }
) { this }

c : class()
f : c.func 		// 'local ()i32
d : heap class()
f : d.func 		// 'heap ()i32
*/
// store as stack
// store as local
// store as heap option
// store as stack option
// store as local option
// get callback from template function
// f : foo!i32
