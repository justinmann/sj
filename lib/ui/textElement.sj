textElement #element (
	font = 'font
	text = 'string
	color = colors.white()
	rect = rect()

	getSize(maxSize : 'size) {
		textSize : rootSurface.getTextSize(font, text)
		textSize.cap(maxSize)	
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect)'void {
		rect = copy rect_
		void
	}

	render(surface : 'surface2d)'void {
		textVertexBuffer : textVertexBuffer(
			text: copy text
		    point: point(rect.x, rect.y)
		    color: copy color
		    font: copy font) as #vertexBuffer

		textSize : surface.getTextSize(font, text)
		final : rect(
			x : rect.x
			y : rect.y
			w : textSize.w
			h : textSize.h
		)
		surface.drawVertexBuffer(textVertexBuffer, font.getTexture())
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}
) { this }