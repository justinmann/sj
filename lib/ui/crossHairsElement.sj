crossHairsElement #element (
	color := colors.white()
	_rect := rect()
	_topDownRenderer := empty'boxRenderer
	_leftRightRenderer := empty'boxRenderer
	_point := point()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { _rect }

	setRect(rect_ : 'rect)'void {
		if _rect != rect_ {
			_rect = copy rect_
			_topDownRenderer = empty'boxRenderer
			_leftRightRenderer = empty'boxRenderer
			void
		}
		void
	}

	render(scene : 'scene2d)'void {
		if isEmpty(_topDownRenderer) {
			_topDownRenderer = value(heap boxRenderer(
			    rect: rect(_point.x, _rect.y, 1, _rect.h)
			    color: copy color))
		}

		if isEmpty(_leftRightRenderer) {
			_leftRightRenderer = value(heap boxRenderer(
			    rect: rect(_rect.x, _point.y, _rect.w, 1)
			    color: copy color))
		}

		_topDownRenderer?.render(scene)
		_leftRightRenderer?.render(scene)
	}

	getChildren()'local array?!#element {
		empty'local array?!#element
	}

	fireMouseEvent(point: 'point, eventId : 'i32)'void {
		if _rect.containsPoint(point) {
			if eventId == mouseEvent_move {
				_point = copy point
				_topDownRenderer = empty'boxRenderer
				_leftRightRenderer = empty'boxRenderer
				void
			}
		}
	}
) { this }