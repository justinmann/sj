include "lib/common/common.sj"

#foo!item(
    test1()'item
)


#bar(
	test2()'i32
)

class!item #bar #foo!item (
    test1() {
        1
    }

    test2() {
    	2
    }
) { this }

a: class!i32() as #foo!i32
a.test1()
b: a as #bar?
b?.test2()