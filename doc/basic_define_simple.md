-- simple class
simple :# (a : 1) { a + 1 }
c : simple(a : 2)

-- compiled version
const global_size = 1
const global_c = 1

const c_size = 1
const c_a = 0

const simple_size = 1
const simple_a = 0

reserve t1, c_size
move t1[c_a], 2
call c, t1, stack
move stack[global_c], result
exit

@simple
move t1, s0[simple_a]
add t1, 1
return t1

@c
call simple, s0, s1
return result