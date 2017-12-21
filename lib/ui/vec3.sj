vec3(
	x : 0.0f
	y : 0.0f
	z : 0.0f

	isEqual(v : 'vec3) {
		x == v.x && y == v.y && z == v.z
	}

	interpolate(v : 'vec3, percent : 'f32) {
		vec3(
			x : x * (1.0f - percent) + v.x * percent
			y : y * (1.0f - percent) + v.y * percent
			z : z * (1.0f - percent) + v.z * percent
		)
	}

	asString() {
		x.asString() + ", " + y.asString() + ", " + z.asString()
	}

	add(v : 'vec3) {
		vec3(
			x + v.x
			y + v.y
			z + v.z
		)	
	}

	subtract(v : 'vec3) {
		vec3(
			x - v.x
			y - v.y
			z - v.z
		)
	}

	normalize() {
		t := f32_sqrt(x * x + y * y + z * z)
		vec3(
			x / t
			y / t
			z / t
		)
	}

	cross(v : 'vec3) {
    	vec3(
    		y * v.z - z * v.y
    		z * v.x - x * v.z
       		x * v.y - y * v.x
    	)
	}

	dot(v : 'vec3) {
    	x * v.x + y * v.y + z * v.z		
	}

	asVec4() {
		vec4(x, y, z, 1.0f)
	}
) { this }

vec3_min(a : 'vec3, b : 'vec3) {
	vec3(
		f32_min(a.x, b.x)
		f32_min(a.y, b.y)
		f32_min(a.z, b.z)
	)
}

vec3_max(a : 'vec3, b : 'vec3) {
	vec3(
		f32_max(a.x, b.x)
		f32_max(a.y, b.y)
		f32_max(a.z, b.z)
	)
}

vec3_getRawSize() {
	--c--
	int x = sizeof(float) * 3;
	#return(i32, x);
	--c--
}

vec3_rawCopy(v : 'vec3, p := 'ptr) {
	--c--
	float* f = (float*)p;
	*f = v->x;
	f++;
	*f = v->y;
	f++;
	*f = v->z;
	f++;
	#return(ptr, (void*)f);
	--c--
}