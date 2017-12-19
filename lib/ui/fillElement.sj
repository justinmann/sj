fillElement #element (
	children : array!heap #element()
	_rect := rect()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect) {
		_rect = copy rect_
		for i : 0 to children.count {
			child : children[i]
			child.setRect(_rect)
		}	
		void	
	}

	render(scene : 'scene2d) {
		for i : 0 to children.count {
			child : children[i]
			child.render(scene)
		}
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
		for i : 0 to children.count {
			child : children[i]
			child.fireMouseEvent(mouseEvent)
		}	
	}
) { this }