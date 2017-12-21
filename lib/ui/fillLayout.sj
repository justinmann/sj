fillLayout #element (
	children : array!heap #element()
	margin := margin()
	_rect := rect()

	getSize(maxSize : 'size) {
		size := size()
		innerSize : maxSize - margin
		for i : 0 to children.count {
			child : children[i]			
			size = size.max(child.getSize(innerSize))
		}
		size + margin
	}

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect) {
		_rect = copy rect_
		innerRect : _rect - margin
		for i : 0 to children.count {
			child : children[i]
			child.setRect(innerRect)
		}	
		void	
	}

	render(scene : 'scene2d) {
		for i : 0 to children.count {
			child : children[i]
			child.render(scene)
		}
	}

	fireMouseEvent(mouseEvent : 'mouseEvent) {
		mouseEvent.fireChildren(children)
	}
) { this }