textElement #element (
	font := 'font
	text := 'string
	color := colors.white()
	_rect := rect()
	_textRenderer := empty'textRenderer

	getSize(maxSize : 'size) {
		textSize : font.getTextSize(text)
		textSize.min(maxSize)	
	}

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect)'void {
		if _rect != rect_ {
			_rect = copy rect_
			_textRenderer = empty'textRenderer
		}
		void
	}

	render(scene : 'scene2d)'void {
		textSize : font.getTextSize(text)
		final : rect(
			x : _rect.x
			y : _rect.y
			w : textSize.w
			h : textSize.h
		)

		if isEmpty(_textRenderer) {
			_textRenderer = valid(textRenderer(
				text: copy text
			    point: point(_rect.x, _rect.y)
			    color: copy color
			    font: copy font))
		}

		_textRenderer?.render(scene)

		void
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
	}
) { this }