include "lib/common/common.sj"

double(x : 'i32) {
	x as f32 * 2.0f
}

lessThan5(x : 'f32) {
	x < 5.0f
}

add(l : 'f32, r : 'f32) {
	l + r
}

sum(
	x := 0.0f
) { this }

sumAdd(sum : 'sum, x : 'f32)'sum {
	sum(sum.x + x)
}

a : [1, 2, 3]
b : a.map!f32(double)
c : b.filter(lessThan5)
d : c.foldl!sum(sum(), sumAdd)