fillElement #element (
	children : array!#element()
	_rect := rect()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { _rect }

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

	getChildren()'local array?!#element {
		a : local children
		value(a)
	}

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
		for i : 0 to children.count {
			child : children[i]
			child.fireMouseEvent(mouseEvent)
		}	
	}
) { this }