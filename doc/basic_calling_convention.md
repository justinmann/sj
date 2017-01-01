"s0" is function stack
"s1" is parent stack

For return value sometimes caller will allocate and pass pointer to function, some times the function will return the pointer as the return value.

Caller allocs space for return value if:
1) return value is created in function block or is "this" pointer
2) return value is not passed into any function that takes "=" parameters
3) return value type is always the same and matches the declared return type


// return instance that could be stack or heap
classA :# () {
	this
}
-- return as sr with type "~classA" meets all rules

// return reference
classA :# (b : classB(3)) {
	b
}
-- return value ":classB" because violated rule 1

// return instance that must be heap
classA :# () {
	object.notify(this)
	this
}
-- return value "=classA" because violated rule 2

// return instance of derived class
classA :# ()object {
	classB(3)
}
-- return value "=object" because violate rule 3


// Example
b : 1
func1 :# (a : 1) classA {
	classA(a + b)	
}

A: func1()


SJ intermediate language
--
reserve stack, global_size
move stack[b], 1

reserve result, func1_return_size
reserve t1, func1_size
move t1[a], 1
call_func func1, t1, stack
release t1
move stack[A], result

release result

exit

@func1
move t1, s0[a]
add t1, s1[b]
move result[a], t1
return

-- with nullable result

b : 1
func1 :# (a : 1) ?classA {
	empty	
}

A: func1() 

SJ intermediate language
--
reserve stack, global_size
move stack[b], 1

reserve result, func1_return_size
reserve t1, func1_size
move t1[a], 1
call_func func1, t1, stack
release t1
move stack[A], result

release result

exit

@func1
move result, null
return


-- with nullable result on heap

b : 1
func1 :# (a : 1) ?classA {
	classA(a + b)	
}

A: func1() 

SJ intermediate language
--
reserve stack, global_size
move stack[b], 1

alloc result, func1_return_size + 1
move result[-1], 1
reserve t1, func1_size
move t1[a], 1
call_func func1, t1, stack
release t1
jnz result, skip_delete_result			// if result is null then delete it
call delete, result
@skip_delete_result
move stack[A], result

dec stack[A][-1]						// deference at end of block
jnz skip_delete_A
call delete, stack[A]
@skip_delete_A

exit

@func1
move t1, s0[a]
add t1, s1[b]
move result[a], t1
return



class: {
	func: (a, b) {
		a * b
	}
}