vec4(
	x : 0.0f
	y : 0.0f
	z : 0.0f
	w : 0.0f

	isEqual(v : 'vec4) {
		x == v.x && y == v.y && z == v.z && w == v.w
	}

	interpolate(v : 'vec4, percent : 'f32) {
		vec4(
			x : x * (1.0f - percent) + v.x * percent
			y : y * (1.0f - percent) + v.y * percent
			z : z * (1.0f - percent) + v.z * percent
			w : w * (1.0f - percent) + v.w * percent
		)
	}

	asString() {
		x.asString() + ", " + y.asString() + ", " + z.asString() + ", " + w.asString()
	}

	add(v : 'vec4) {
		vec4(
			x + v.x
			y + v.y
			z + v.z
			w + v.w
		)	
	}

	subtract(v : 'vec4) {
		vec4(
			x - v.x
			y - v.y
			z - v.z
			w - v.w
		)
	}

	normalize() {
		t := f32_sqrt(x * x + y * y + z * z + w * w)
		vec4(
			x / t
			y / t
			z / t
			w / t
		)
	}

	dot(v : 'vec4) {
    	x * v.x + y * v.y + z * v.z	 + w * v.w	
	}

	asVec3() {
		vec3(x / w, y / w, z / w)
	}
) { this }

vec4_min(a : 'vec4, b : 'vec4) {
	vec4(
		f32_min(a.x, b.x)
		f32_min(a.y, b.y)
		f32_min(a.z, b.z)
		f32_min(a.w, b.w)
	)
}

vec4_max(a : 'vec4, b : 'vec4) {
	vec4(
		f32_max(a.x, b.x)
		f32_max(a.y, b.y)
		f32_max(a.z, b.z)
		f32_max(a.w, b.w)
	)
}