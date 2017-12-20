boxElement #element (
	color := colors.white()
	idealSize := size()
	rect := rect()
	boxRenderer := empty'boxRenderer

	getSize(maxSize : 'size) {
		idealSize.min(maxSize)
	}

	getRect()'rect { copy rect }

	setRect(rect_ : 'rect)'void {
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