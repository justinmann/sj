textElement #element (
	font := 'font
	text := 'string
	color := colors.white()
	rect := rect()
	textRenderer := empty'textRenderer

	getSize(maxSize : 'size) {
		textSize : font.getTextSize(text)
		textSize.cap(maxSize)	
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		if rect != rect_ {
			rect = copy rect_
			textRenderer = empty'textRenderer
		}
		void
	}

	render(scene : 'scene2d)'void {
		textSize : font.getTextSize(text)
		final : rect(
			x : rect.x
			y : rect.y
			w : textSize.w
			h : textSize.h
		)

		if isEmpty(textRenderer) {
			textRenderer = valid(heap textRenderer(
				text: copy text
			    point: point(rect.x, rect.y)
			    color: copy color
			    font: copy font))
		}

		textRenderer?.render(scene)

		void
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
	}
) { this }