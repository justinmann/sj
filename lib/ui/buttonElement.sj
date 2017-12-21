enum buttonState (
	normal
	hot
	pressed
)

buttonElement #element (
	text := ""
	textColor := copy colors.black
	font := style.getFont()
	normalImage := valid(image(textureFromPng("assets/buttonNormal.png"), margin := margin(2, 2, 2, 2)))
	hotImage := valid(image(textureFromPng("assets/buttonHot.png"), margin := margin(2, 2, 2, 2)))
	pressedImage := valid(image(textureFromPng("assets/buttonPressed.png"), margin := margin(2, 2, 2, 2)))
	margin := margin(10, 10, 10, 10)
	onClick := empty'heap ()void
	_rect := rect()
	_state := buttonState.normal
	_textRenderer := empty'textRenderer
	_imageRenderer := empty'imageRenderer

	getSize(maxSize : 'size) {
		textSize : font.getTextSize(text) + margin
		textSize.min(maxSize)	
	}

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect) {
		if _rect != rect_ {
			_rect = copy rect_
			_textRenderer = empty'textRenderer
			_imageRenderer = empty'imageRenderer
		}
		void
	}

	getState()'buttonState { _state }
	setState(state_ : 'buttonState) {
		if _state != state_ {
			_state = state_
			_imageRenderer = empty'imageRenderer
		}
		void
	}

	render(scene : 'scene2d) {
		if isEmpty(_imageRenderer) {
			image : switch _state {
				buttonState.hot 	{ copy hotImage }
				buttonState.pressed { copy pressedImage }
				default				{ copy normalImage }
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

	onMouseUp(point : 'point)'bool {
		if mouse_hasCapture(heap parent as #element) {
			mouse_release(heap parent as #element)
			ifValid onClick {
				onClick()
			}
			setState(buttonState.normal)
			false
		} else {
			true
		}
	}

	onMouseDown(point : 'point)'bool {
		mouse_capture(heap parent as #element)
		setState(buttonState.pressed)
		false
	}

	onMouseMove(point : 'point)'bool {
		if _state == buttonState.normal {
			setState(buttonState.hot)
		}
		true
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'bool {
		heap parent // TODO: ugly
		if _rect.containsPoint(mouseEvent.point) {
			if mouseEvent.type == mouseEventType.up {
				onMouseUp(mouseEvent.point)
			} else if mouseEvent.type == mouseEventType.down {
				onMouseDown(mouseEvent.point)
			} else if mouseEvent.type == mouseEventType.move {
				onMouseMove(mouseEvent.point)
			} else {
				true
			}
		} else {
			true
		}
	}
) { this }