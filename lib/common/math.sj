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

f32_pi : 3.14159265358979323846f
u32_maxValue : 4294967295u

i32_maxValue : -1i - 2147483647i
i32_minValue : 2147483647i

i32_max(a : 'i32, b : 'i32)'i32 {
	if a < b { b } else { a }
}

i32_min(a : 'i32, b : 'i32)'i32 {
	if a < b { a } else { b }
}