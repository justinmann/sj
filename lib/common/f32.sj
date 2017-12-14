f32_pi : 3.14159265358979323846f

f32_sqrt(v : 'f32)'f32 {
	result := 0.0f
	--c--
	sjv_result = sqrtf(v);
	--c--
	result
}

f32_cos(v : 'f32)'f32 {
	result := 0.0f
	--c--
	sjv_result = cosf(v);
	--c--
	result
}

f32_sin(v : 'f32)'f32 {
	result := 0.0f
	--c--
	sjv_result = sinf(v);
	--c--
	result
}

f32_tan(v : 'f32)'f32 {
	result := 0.0f
	--c--
	sjv_result = tanf(v);
	--c--
	result
}

f32_max(a : 'f32, b : 'f32)'f32 {
	if a < b { b } else { a }
}

f32_min(a : 'f32, b : 'f32)'f32 {
	if a < b { a } else { b }
}

f32_random()'f32 {
	x := 0.0f
	--c--
	sjv_x = (float)rand() / (float)RAND_MAX;
	--c--
	x
}

f32_toString(val : 'f32) {
	count := 0
	data := 0 as ptr
	--c--
	sjv_data = (uintptr_t)malloc(sizeof(char) * 50);
	snprintf((char*)sjv_data, 50, "%f", val);
	sjv_count = strlen((char*)sjv_data);
	--c--
	string(count := count, data := array!char(size := count + 1, data := data))
}