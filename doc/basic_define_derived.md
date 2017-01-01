classB :# (a : 2) {
	this
}

classA :# classB(a : 3) {
	base
}

c : classA(a : 1)

--- stack allocation
const global_size = 1
const global_c = 0

const classA_size = 1
const classA_a = 0

const classB_size = 1
const classB_a = 0

reserve t1, classA_size
move stack[classB_a], 2
move stack[classA_a], 3
move stack[classA_a], 1
call classB, t1
call classA, t1
move c, *result
exit

@classB
call init1, stack[0]
return stack[0]

@classA
call init2, stack[0]
return stack[0]


--- heap allocation
const classA_size = 1
const classA_a = 0
const classB_size = 1
const classB_a = 0

alloc classA_size + 1		// ref count is store at static[-1] so we need to alloc +1 the actual size then move pointer
inc result
move t1, result
move t1[-1], 1
move t1[classB_a], 2
move t1[classA_a], 3
move t1[classA_a], 1
call classB, t1, stack
call classA, t1, stack
inc result[-1]
move stack[global_c], result

dec t1[-1]						// deference at end of block
jnz skip_delete_t1
call delete, t1

@skip_delete_t1
move t2, stack[global_c]
dec t2[-1]
jnz skip_delete_c
call delete, t2

exit

@classB
return s0

@classA
call classB, s0, s1
return result