textElement #element (
	font = 'font
	text = 'string
	color = colors.white()
	rect = rect()
	textRenderer = empty'textRenderer

	getSize(maxSize : 'size) {
		textSize : font.getTextSize(text)
		textSize.cap(maxSize)	
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		rect = copy rect_
		void
	}

	render(surface : 'surface2d)'void {
		textSize : font.getTextSize(text)
		final : rect(
			x : rect.x
			y : rect.y
			w : textSize.w
			h : textSize.h
		)

		if isEmpty(textRenderer) {
			textRenderer = value(heap textRenderer(
				text: copy text
			    point: point(rect.x, rect.y)
			    color: copy color
			    font: copy font))
		}

		textRenderer?.render(surface)

		void
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }