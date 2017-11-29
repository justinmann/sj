rect(
	x : 0
	y : 0
	w : 0
	h : 0

	addMargin(l : 0, t : 0, r : 0, b : 0) {
		rect(x + l, y + t, w - l - r, h - t - b)
	}
) { this }