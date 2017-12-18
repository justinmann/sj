imageElement #element (
	image := 'image
	_rect := rect()
	_margin := margin(10, 10, 10, 10)
	_imageRenderer := empty'imageRenderer

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { _rect }

	setRect(rect_ : 'rect)'void {
		if _rect != rect_ {
			_rect = copy rect_
			_imageRenderer = empty'imageRenderer
		}
		void
	}

	render(scene : 'scene2d)'void {
		if isEmpty(_imageRenderer) {
			_imageRenderer = value(imageRenderer(
				image : copy image
				rect : _rect.subtractMargin(_margin)
			))

			void
		}

		_imageRenderer?.render(scene)
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
	}
) { this }