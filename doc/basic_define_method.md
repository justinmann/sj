classB :# (
	a: 2
	func1 :# (b: 4) { parent.a + 1 }
)

classA :# classB(
	a: 3
	func1 :# (b : 5, [outer] f : empty#()int) { 		// if parameter matches classB class parameter then it overrides
		base + b + parent.a + f()   // base is special keyword that calls the class that was overriden
	}
)

c : classA(a : 1)
c.func1() {
	c.a + 1
}

--- heap allocation
const global_size = 1
const global_c = 0

const func1_size = 0

const classA_size = 2
const classA_a = 0
const classA_func1 = 1

const classA_func1_size = 3
const classA_func1_b = 1
const classA_func1_f
const classA_func1_f_parent

const classB_size = 2
const classB_a = 0
const classB_func1 = 1

const classB_func1_size = 1
const classB_func1_b = 1

// classB
reserve t2, classB_size
move t2[classB_a], 2
move t2[classB_func1_f], func1
move t2[classB_func1_f_parent], t2
call classB, t2, stack
move stack[global_classB], result

// c: classA(a: 1)
call alloc, classA_size	+ 1			// ref count is stored at static[-1] so we need to alloc +1 the actual size then move pointer
inc result
move t1, result
move t1[-1], 1
move t1[classA_a], 1
move t1[classA_func1], classA_func1
call classA, t1, null
inc result[-1]
move stack[global_c], result

reserve t3, func1_size
move t3[func1_parent], stack

// c.func1()
reserve t2, classA_func1_size
move t2[classA_func1_b], 5
move t2[classA_func1_f], func1
move t2[classA_func1_f_parent], stack
call c[classA_func1], t2, t1

dec t1[-1]						// deference at end of block
jnz skip_delete_t1
call delete, t1

@skip_delete_t1
move t2, stack[global_c]
dec t2[-1]
jnz skip_delete_c
call delete, t2

@skip_delete_c
exit

@classB
return s0

@classA
call classB, s0, s1
return s0

@classB_func1
move t1, s1[classB_a]
inc t1
return t1

@classA_func1
call_func classB_func1, s0, s1
move t1, *result
add t1, s0[classA_func1_b]
add t1, s1[classA_a]

reserve t1, func1_size
call s0[classA_func1_b], t1, s0[classA_func1_b_parent]
return t1

@func1
move t1, s1[global_c]
move t2, t1[classA_a]
inc t2
return t2
