// if there is no `#` then it will execute the block making it static
staticA : (a : 2) {
	init1()
	this
}

c : staticA.a

--- stack allocation
const global_size = 1
const global_staticA = 0

const staticA_size = 1
const staticA_a = 0

reserve t1, staticA_size
move t1[staticA_a], 2
call staticA_init, t1, stack
move stack[global_staticA], result

move t2, stack[global_staticA] 
move c, t2[staticA_a]
exit

@staticA_init
call init1, s0
return s0