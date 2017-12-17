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
	data := nullptr
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

	if (sjv_count < minlength) {				
	}

	sjv_data = malloc(sizeof(char) * (sjv_count + 1));
	memcpy(sjv_data, &buf[i+1], sjv_count + 1);
	--c--
	string(count := count, data := array!char(dataSize := count + 1, count := count + 1, data := data))
}

i32_compare(l : 'i32, r : 'i32) {
	if l == r {
		0
	} else if l < r {
		-1
	} else {
		1
	}
}

i32_hash(val : 'i32)'u32 {
	val as u32
}

i32_isEqual(l : 'i32, r : 'i32)'bool {
	l == r
}

string_toI32(text : 'string)'i32 {
	x := 0
	--c--
	char* e;
    int v = (int)strtol((char*)text->data.data, &e, 10);
    
    if (*e != '\0') {
        sjv_x = 0;
    }
    else {
    	sjv_x = v;
	}
    --c--
    x
}

