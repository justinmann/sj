f32_sqrt(v : 'f32)'f32 {
	result = 0.0f
	--c--
	sjv_result = sqrtf(v);
	--c--
	result
}

f32_cos(v : 'f32)'f32 {
	result = 0.0f
	--c--
	sjv_result = cosf(v);
	--c--
	result
}

f32_sin(v : 'f32)'f32 {
	result = 0.0f
	--c--
	sjv_result = sinf(v);
	--c--
	result
}

f32_tan(v : 'f32)'f32 {
	result = 0.0f
	--c--
	sjv_result = tanf(v);
	--c--
	result
}

f32_pi = 3.14159265358979323846f

i32_max: -2147483648i
i32_min: 2147483647i
u32_max: 4294967295u