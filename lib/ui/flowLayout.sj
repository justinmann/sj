enum flowLayoutOrientation(
	topBottom
	leftRight
	bottomTop
	rightLeft
)

flowLayout #element (
	children : array!heap #element()
	margin := margin()
	orientation := flowLayoutOrientation.leftRight
	_rect := rect()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'rect { copy _rect }

	setRect(rect_ : 'rect) {
		_rect = copy rect_
		innerRect : rect_ - margin

		val1 := 0
		val2 := 0
		valMax := 0
		for i : 0 to children.count {		
			child : children[i]
			switch orientation {
				flowLayoutOrientation.topBottom {
					childSize : child.getSize(size(innerRect.w, innerRect.h))
					valMax = valMax.max(childSize.w)
					if (val1 + childSize.h > innerRect.h) {
						val1 = 0
						val2 += valMax
						valMax = 0
					} 

					child.setRect(rect(innerRect.x + val2, innerRect.y + val1, childSize.w, childSize.h))
					val1 += childSize.h
				}
				flowLayoutOrientation.bottomTop {
					childSize : child.getSize(size(innerRect.w, innerRect.h))
					valMax = valMax.max(childSize.w)
					if (val1 + childSize.h >= innerRect.h) {
						val1 = 0
						val2 += valMax
						valMax = 0
					} 

					child.setRect(rect(innerRect.x + val2, innerRect.y + innerRect.h - val1 - childSize.h, childSize.w, childSize.h))
					val1 += childSize.h
				}
				flowLayoutOrientation.leftRight {
					childSize : child.getSize(size(innerRect.w, innerRect.h))
					valMax = valMax.max(childSize.h)
					if (val1 + childSize.w > innerRect.w) {
						val1 = 0
						val2 += valMax
						valMax = 0
					} 

					child.setRect(rect(innerRect.x + val1, innerRect.y + val2, childSize.w, childSize.h))
					val1 += childSize.w
				}
				flowLayoutOrientation.rightLeft {
					childSize : child.getSize(size(innerRect.w, innerRect.h))
					valMax = valMax.max(childSize.h)
					if (val1 + childSize.w > innerRect.w) {
						val1 = 0
						val2 += valMax
						valMax = 0
					} 

					child.setRect(rect(innerRect.x + innerRect.w - val1 - childSize.w, innerRect.y + val2, childSize.w, childSize.h))
					val1 += childSize.w
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

	fireMouseEvent(mouseEvent : 'mouseEvent)'void {
		for i : 0 to children.count {
			child : children[i]
			child.fireMouseEvent(mouseEvent)
		}	
	}
) { this }