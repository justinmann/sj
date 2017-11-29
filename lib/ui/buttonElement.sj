buttonState: ^(
	normal : 0
	hot : 1
	pressed : 2
) { this }

buttonElement #element #mouseHandler (
	text = ""
	textColor = colors.green()
	font = style.getFont(0 /* TODO: typeId(button) */)
	rect = rect()
	normalImage = image()
	hotImage = image()
	pressedImage = image()
	state = buttonState.normal

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
		textRect : rect(
			x : (rect.w - textSize.w) / 2
			y : (rect.h - textSize.h) / 2
			w : textSize.w
			h : textSize.h
		)
		surface.drawText(textRect, font, text, textColor)

		// TODO: change color based on state
		// TODO: support nine-grid image background
		// TODO: render text
		void
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	onMouseUp(point : 'point)'void {
		console.write("buttonElement onMouseUp " + convert.i32toString(point.x) + ", " + convert.i32toString(point.y))
	}

	onMouseDown(point : 'point)'void {
		console.write("buttonElement onMouseDown")
	}

	onMouseMove(point : 'point)'void {
		console.write("buttonElement onMouseMove")
	}

) { this }