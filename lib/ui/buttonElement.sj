buttonState: ^(
	normal : 0
	hot : 1
	pressed : 2
) { this }

buttonElement #element #mouseHandler (
	text = ""
	textColor = colors.black()
	font = style.getFont(0 /* TODO: typeId(button) */)
	rect = rect()
	normalImage = image(rootSurface.getTexture(src = "assets/buttonNormal.png"), margin = margin(2, 2, 2, 2))
	hotImage = image(rootSurface.getTexture(src = "assets/buttonHot.png"), margin = margin(2, 2, 2, 2))
	pressedImage = image(rootSurface.getTexture(src = "assets/buttonPressed.png"), margin = margin(2, 2, 2, 2))
	state = buttonState.normal
	margin = margin(10, 10, 10, 10)

	getSize(maxSize : 'size) {
		textSize : rootSurface.getTextSize(font, text)
		textSize.addMargin(margin).cap(maxSize)	
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect) {
		rect = copy rect_
		void
	}

	render(surface : '#surface) {
		if (state == buttonState.normal) {
			surface.drawImage(rect, normalImage)
		} else if (state == buttonState.hot) {
			surface.drawImage(rect, hotImage)
		} else if (state == buttonState.pressed) {
			surface.drawImage(rect, pressedImage)
		}

		textSize : surface.getTextSize(font, text)
		innerRect : rect.subtractMargin(margin)
		textRect : rect(
			x : innerRect.x + (innerRect.w - textSize.w) / 2
			y : innerRect.y + (innerRect.h - textSize.h) / 2
			w : textSize.w
			h : textSize.h
		)
		surface.drawText(textRect, font, text, textColor)

		// TODO: change color based on state
		// TODO: support nine-grid image background
		void
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	onMouseUp(point : 'point)'void {
		console.write("buttonElement onMouseUp " + convert.i32toString(point.x) + ", " + convert.i32toString(point.y))
		state = buttonState.normal
		void
	}

	onMouseDown(point : 'point)'void {
		console.write("buttonElement onMouseDown")
		state = buttonState.pressed
		void
	}

	onMouseMove(point : 'point)'void {
		console.write("buttonElement onMouseMove")
		if state == buttonState.normal {
			state = buttonState.hot
		}
		void
	}

) { this }