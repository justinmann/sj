size(
	w : 0
	h : 0

	cap(maxSize : 'size) {
		size(
			if w < maxSize.w { w } else { maxSize.w },
			if h < maxSize.h { h } else { maxSize.h }
		)
	}
) { this }