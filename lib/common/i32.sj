u32_maxValue : 4294967295u

i32_maxValue : -1i - 2147483647i
i32_minValue : 2147483647i

i32_max(a : 'i32, b : 'i32)'i32 {
	if a < b { b } else { a }
}

i32_min(a : 'i32, b : 'i32)'i32 {
	if a < b { a } else { b }
}

i32_random()'i32 {
	x := 0
	--c--
	sjv_x = rand();
	--c--
	x
}