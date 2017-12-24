@heap
buttonElement #element #clickable(
	text := ""
	textColor := copy colors.black
	font := style.getFont()
	normalImage := valid(image(texture_fromPng("assets/buttonNormal.png"), margin := margin(2, 2, 2, 2)))
	hotImage := valid(image(texture_fromPng("assets/buttonHot.png"), margin := margin(2, 2, 2, 2)))
	pressedImage := valid(image(texture_fromPng("assets/buttonPressed.png"), margin := margin(2, 2, 2, 2)))
	margin := margin(10, 10, 10, 10)
	onClick := empty'heap ()void
	_rect := rect()
	_textRenderer := empty'textRenderer
	_imageRenderer := empty'imageRenderer
	_clickGesture := clickGesture() // TODO:

	getSize(maxSize : 'size) {
		textSize : font.getTextSize(text) + margin
		textSize.min(maxSize)	
	}

	getRect() { copy _rect }
	setRect(rect_ : 'rect) {
		if _rect != rect_ {
			_rect = copy rect_
			_clickGesture.rect = copy rect_
			_textRenderer = empty'textRenderer
			_imageRenderer = empty'imageRenderer
		}
		void
	}

	render(scene : 'scene2d) {
		if isEmpty(_imageRenderer) {
			image : switch _clickGesture.state {
				clickState.entered { copy hotImage }
				clickState.pressed { copy pressedImage }
				default			   { copy normalImage }
			}

			ifValid image {
				_imageRenderer = valid(imageRenderer(
					image : copy image
					rect : copy _rect			
				))
			}
		}

		if isEmpty(_textRenderer) {
			innerRect : _rect.subtractMargin(margin)

			textSize : font.getTextSize(text)

			_textRenderer = valid(textRenderer(
				text: copy text
			    point: point(innerRect.x + (innerRect.w - textSize.w) / 2, innerRect.y + (innerRect.h - textSize.h) / 2)
			    color: copy textColor
			    font: copy font))
		}

		_imageRenderer?.render(scene)
		_textRenderer?.render(scene)
		void
	}

	onClickGestureEnter(element : '#element) {
		_imageRenderer = empty'imageRenderer
		void
	}

	onClickGestureLeave(element : '#element) {
		_imageRenderer = empty'imageRenderer
		void
	}

	onClickGesturePress(element : '#element) {
		_imageRenderer = empty'imageRenderer
		void
	}

	onClickGestureClick(element : '#element) {
		_imageRenderer = empty'imageRenderer
		ifValid onClick {
			onClick()
		}
		void
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'bool {
		_clickGesture.fireMouseEvent(mouseEvent)
	}
) { 
	_clickGesture = clickGesture(this as #element, this as #clickable)
	this 
}