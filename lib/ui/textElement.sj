textElement #element (
	font = 'font
	text = 'string
	color = colors.white()
	rect = rect()

	setRect(rect_ : 'rect)'void {
		rect = copy rect_.addMargin(10, 10, 10, 10)
		void
	}

	render(surface : '#surface)'void {
		textSize : surface.getTextSize(font, text)
		final : rect(
			x : rect.x
			y : rect.y
			w : textSize.w
			h : textSize.h
		)
		surface.drawText(final, font, text, color)
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }