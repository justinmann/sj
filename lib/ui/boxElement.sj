boxElement #element (
	color = colors.white()
	idealSize = size()
	rect = rect()
	boxRenderer = empty'boxRenderer

	getSize(maxSize : 'size) {
		idealSize.cap(maxSize)
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		rect = copy rect_
		void
	}

	render(surface : 'surface2d)'void {
		if isEmpty(boxRenderer) {
			boxRenderer = value(heap boxRenderer(
			    rect: copy rect
			    color: copy color))
		}

		boxRenderer?.render(surface)
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }