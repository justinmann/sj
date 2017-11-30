boxElement #element (
	color = colors.white()
	idealSize = size()
	rect = rect()

	getSize(maxSize : 'size) {
		idealSize.cap(maxSize)
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		rect = copy rect_
		void
	}

	render(surface : '#surface)'void {
		surface.drawRect(rect, color)
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }