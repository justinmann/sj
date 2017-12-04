colors : ^(
	red()   { color(1.0f, 0.0f, 0.0f) }
	green() { color(0.0f, 1.0f, 0.0f) }
	blue()  { color(0.0f, 0.0f, 1.0f) }
	black() { color(0.0f, 0.0f, 0.0f) }
	white() { color(1.0f, 1.0f, 1.0f) }
) { this }

color(
	r : 'f32
	g : 'f32
	b : 'f32
	a : 1.0f

	asString() {
		"#" + convert.i32toString((a * 255.0f) as i32, 16, 2) + convert.i32toString((r * 255.0f) as i32, 16, 2) + convert.i32toString((g * 255.0f) as i32, 16, 2) + convert.i32toString((b * 255.0f) as i32, 16, 2)
	}
) { this }