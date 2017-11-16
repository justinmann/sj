convert: ^(
	i32toString(val : 'i32, base : 10, minLength : 0) {
		count = 0
		data = 0 as ptr
		c{
			if (base < 2) {
				printf("base is too small");
				exit(-1);
			}

			if (base > 16) {
				printf("base is too large");
				exit(-1);
			}

			char buf[32] = { 0 };
			int i = 30;	
			do {
				buf[i] = "0123456789ABCDEF"[val % base];	
				i--;
				val /= base;
			} while (val && i);
			count = 30 - i;

			if (count < minLength) {				
			}

			data = (uintptr_t)malloc(sizeof(char) * (count + 1));
			memcpy((void*)data, &buf[i+1], count + 1);
			printf("%s\n", (char*)data);
		}c
		string(count = count, data = array!char(size = count + 1, data = data))
	}
) { this }