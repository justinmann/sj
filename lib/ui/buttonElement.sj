enum buttonState (
	normal
	hot
	pressed
)

buttonElement #element (
	text := ""
	textColor := colors.blue()
	font := style.getFont(0 /* TODO: typeId(button) */)
	normalImage := image(textureFromPng("assets/buttonNormal.png"), margin := margin(2, 2, 2, 2))
	hotImage := image(textureFromPng("assets/buttonHot.png"), margin := margin(2, 2, 2, 2))
	pressedImage := image(textureFromPng("assets/buttonPressed.png"), margin := margin(2, 2, 2, 2))
	margin := margin(10, 10, 10, 10)
	_rect := rect()
	_state := buttonState.normal
	_textRenderer := empty'textRenderer
	_imageRenderer := empty'imageRenderer

	getSize(maxSize : 'size) {
		textSize : font.getTextSize(text)
		textSize.addMargin(margin).cap(maxSize)	
	}

	getRect()'local rect { _rect }

	setRect(rect_ : 'rect) {
		if _rect != rect_ {
			_rect = copy rect_
			_textRenderer = empty'textRenderer
			_imageRenderer = empty'imageRenderer;
		}
		void
	}

	getState()'i32 {
		_state
	}

	setState(state_ : 'i32) {
		if _state != state_ {
			_state = state_
			_imageRenderer = empty'imageRenderer;
		}
	}

	render(scene : 'scene2d) {
		if isEmpty(_imageRenderer) {
			image : local (if (_state == buttonState.hot) {
					hotImage
				} else if (_state == buttonState.pressed) {
					pressedImage
				} else {
					normalImage
				})

			_imageRenderer = valid(heap imageRenderer(
				image : copy image
				rect : copy _rect			
			))

			void
		}

		if isEmpty(_textRenderer) {
			innerRect : _rect.subtractMargin(margin)

			textSize : font.getTextSize(text)

			_textRenderer = valid(heap textRenderer(
				text: copy text
			    point: point(innerRect.x + (innerRect.w - textSize.w) / 2, innerRect.y + (innerRect.h - textSize.h) / 2)
			    color: copy textColor
			    font: copy font))

			void
		}

		_imageRenderer?.render(scene)
		_textRenderer?.render(scene)
		void
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	onMouseUp(point : 'point)'void {
		console.write("buttonElement onMouseUp " + convert.i32asString(point.x) + ", " + convert.i32asString(point.y))
		mouse_capture(heap parent as #element)
		state = buttonState.normal
		void
	}

	onMouseDown(point : 'point)'void {
		console.write("buttonElement onMouseDown")
		mouse_release(heap parent as #element)
		state = buttonState.pressed
		void
	}

	onMouseMove(point : 'point)'void {
		console.write("buttonElement onMouseMove")
		if _state == buttonState.normal {
			state = buttonState.hot
		}
		void
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
		if _rect.containsPoint(mouseEvent.point) {
			if mouseEvent.type == mouseEventType.up {
				onMouseUp(point)
			} else if mouseEvent.type == mouseEventType.down {
				onMouseDown(point)
			} else if mouseEvent.type == mouseEventType.move {
				onMouseMove(point)
			}
		}
	}
) { this }