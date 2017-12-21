boxElement #element (
	color := copy colors.white
	idealSize := size()
	rect := rect()
	boxRenderer := empty'boxRenderer

	getSize(maxSize : 'size) {
		debug.writeLine("boxElement:getSize:" + maxSize.asString())
		idealSize.min(maxSize)
	}

	getRect()'rect { copy rect }

	setRect(rect_ : 'rect)'void {
		debug.writeLine("boxElement:setRect:" + rect_.asString())
		if rect != rect_ {
			rect = copy rect_
			boxRenderer = empty'boxRenderer
		}
		void
	}

	render(scene : 'scene2d)'void {
		if isEmpty(boxRenderer) {
			boxRenderer = valid(boxRenderer(
			    rect: copy rect
			    color: copy color))
		}

		boxRenderer?.render(scene)
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void { }
) { this }