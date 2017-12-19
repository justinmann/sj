include "lib/common/common.sj"

#foo(
    test()'i32
    isEqual(f:'#foo)'bool
)

class #foo (
	x : 'i32
    test() { x }
    isEqual(f:'#foo)'bool {
    	test() == f.test()
    }
) { this }

a : class(1) as #foo
b : class(1) as #foo

t1 : a === a
t2 : a === b
t3 : a == b