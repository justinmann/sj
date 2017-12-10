convert: ^(
	i32toString(val : 'i32, base : 10, minLength : 0) {
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
		string(count := count, data := array!char(size := count + 1, data := data))
	}

	f32toString(val : 'f32) {
		count := 0
		data := 0 as ptr
		--c--
		sjv_data = (uintptr_t)malloc(sizeof(char) * 50);
		snprintf((char*)sjv_data, 50, "%f", val);
		sjv_count = strlen((char*)sjv_data);
		--c--
		string(count := count, data := array!char(size := count + 1, data := data))
	}
) { this }