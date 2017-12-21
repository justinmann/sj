enum textHorizontal(
	left
	right
	center
)

enum textVertical(
	top
	bottom
	center
)

textElement #element (
	font := style.getFont()
	text := string()
	color := copy colors.white
	margin := margin()
	halign := textHorizontal.left
	valign := textVertical.top
	_rect := rect()
	_textRenderer := empty'textRenderer

	getSize(maxSize : 'size) {
		textSize : font.getTextSize(text) + margin
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
		if isEmpty(_textRenderer) {
			textSize : font.getTextSize(text)
			innerRect : _rect - margin
			x : switch halign {
				textHorizontal.left 	{ innerRect.x }
				textHorizontal.right 	{ innerRect.x + innerRect.w - textSize.w }
				textHorizontal.center 	{ innerRect.x + (innerRect.w - textSize.w) / 2 }
				default					{ 0 }
			}

			y : switch valign {
				textVertical.top 		{ innerRect.y }
				textVertical.bottom 	{ innerRect.y + innerRect.h - textSize.h }
				textVertical.center 	{ innerRect.y + (innerRect.h - textSize.h) / 2 }
				default					{ 0 }
			}

			_textRenderer = valid(textRenderer(
				text: copy text
			    point: point(x, y)
			    color: copy color
			    font: copy font))
		}

		_textRenderer?.render(scene)

		void
	}

	fireMouseEvent(mouseEvent : 'mouseEvent) {
		true
	}
) { this }