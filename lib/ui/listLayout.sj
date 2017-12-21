enum listLayoutOrientation(
	topBottom
	leftRight
	bottomTop
	rightLeft
)

listLayout #element (
	children : array!heap #element()
	margin := margin()
	orientation := listLayoutOrientation.leftRight
	_rect := rect()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect) {
		_rect = copy rect_
		innerRect : rect_ - margin

		val := 0
		for i : 0 to children.count {		
			child : children[i]
			switch orientation {
				listLayoutOrientation.topBottom {
					childSize : child.getSize(size(innerRect.w, innerRect.h - val))
					child.setRect(rect(innerRect.x, innerRect.y + val, innerRect.w, childSize.h))
					val += childSize.h
				}
				listLayoutOrientation.bottomTop {
					childSize : child.getSize(size(innerRect.w, innerRect.h - val))
					child.setRect(rect(innerRect.x, innerRect.y + innerRect.h - val - childSize.h, innerRect.w, childSize.h))
					val += childSize.h
				}
				listLayoutOrientation.leftRight {
					childSize : child.getSize(size(innerRect.w - val, innerRect.h))
					child.setRect(rect(innerRect.x + val, innerRect.y, childSize.w, innerRect.h))
					val += childSize.w
				}
				listLayoutOrientation.rightLeft {
					childSize : child.getSize(size(innerRect.w - val, innerRect.h))
					child.setRect(rect(innerRect.x + innerRect.w - val - childSize.w, innerRect.y, childSize.w, innerRect.h))
					val += childSize.w
				}
			}
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