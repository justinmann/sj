convert: ^(
	i32toString(val : 'i32) {
		count = 0
		data = 0 as ptr
		c{
			char buf[32] = { 0 };
			int i = 30;	
			for(; val && i ; --i, val /= 10)	
				buf[i] = "0123456789"[val % 10];	

			count = 30 - i;
			data = (uintptr_t)malloc(sizeof(char) * (count + 1));
			memcpy(&buf[i+1], (void*)data, count + 1);
		}c
		string(count = count, data = array!char(size = count + 1, data = data))
	}
) { this }