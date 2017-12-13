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

i32_toString(val : 'i32, base : 10, minLength : 0) {
	count := 0
	data := 0 as ptr
	--c--
	if (base < 2) {
		halt("base is too small");
	}

	if (base > 16) {
		halt("base is too large");
	}

	char buf[32] = { 0 };
	int i = 30;	
	do {
		buf[i] = "0123456789ABCDEF"[val % base];	
		i--;
		val /= base;
	} while (val && i);
	sjv_count = 30 - i;

	if (sjv_count < minLength) {				
	}

	sjv_data = (uintptr_t)malloc(sizeof(char) * (sjv_count + 1));
	memcpy((void*)sjv_data, &buf[i+1], sjv_count + 1);
	--c--
	string(count := count, data := array!char(dataSize := count + 1, count := count + 1, data := data))
}

