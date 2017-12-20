size(
	w : 0
	h : 0

	min(maxSize : 'size) {
		size(
			if w < maxSize.w { w } else { maxSize.w }
			if h < maxSize.h { h } else { maxSize.h }
		)
	}

	addMargin(margin : 'margin) {
		size(w + margin.l + margin.r, h + margin.t + margin.b)
	}

	isEqual(size: 'size) {
		w == size.w && h == size.h
	}

	toString() {
		"w: " + w.toString() + " h: " + h.toString() 
	}
) { this }