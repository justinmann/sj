vec3(
	x : 0.0f
	y : 0.0f
	z : 0.0f

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
    		y * v.z - z * v.y;
    		z * v.x - x * v.z;
    		x * v.y - y * v.x;	
    	)
	}

	dot(v : 'vec3) {
    	x * v.x + y * v.y + z * v.z		
	}
) { this }
