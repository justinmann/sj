include "lib/common/common.sj"

double(x : 'i32) {
	x * 2
}

a : [1, 2, 3]
b : a.map!i32(double)