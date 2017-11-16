color(
	r : 'i32
	g : 'i32
	b : 'i32
	a : 255

	asString() {
		"#" + convert.i32toString(a, 16, 2) + convert.i32toString(r, 16, 2) + convert.i32toString(g, 16, 2) + convert.i32toString(b, 16, 2)
	}
) { this }