colors : ^(
	red() { color(255, 0, 0) }
	green() { color(0, 255, 0) }
	blue() { color(0, 0, 255) }
	black() { color(0, 0, 0) }
	white() { color(255, 255, 255) }
) { this }

color(
	r : 'i32
	g : 'i32
	b : 'i32
	a : 255

	asString() {
		"#" + convert.i32toString(a, 16, 2) + convert.i32toString(r, 16, 2) + convert.i32toString(g, 16, 2) + convert.i32toString(b, 16, 2)
	}
) { this }