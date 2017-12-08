borderPosition:^(
	fill : 0
	left : 1
	right : 2
	top : 3
	bottom : 4
) { this }

#borderChild(
	getPosition()'i32
)

borderChild #element #borderChild (
	child : 'heap #element
	rect = rect(0, 0, 0, 0)
	position = borderPosition.fill
	_children = empty'heap array!#element

	getPosition() { position }

	getSize(maxSize : 'size) {
		child.getSize(maxSize)
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect) {
		rect = copy rect_
		child.setRect(rect : rect)
		void	
	}

	render(scene : 'scene2d) {
		child.render(scene)
	}

	getChildren()'local array?!#element {
		if isEmpty(_children) {
			_children = value([child])
		}
		_children
	}
) { this }

borderLayout #element (
	children : array!#element()
	rect = rect()

	getSize(maxSize : 'size) {
		size(maxSize.w, maxSize.h)
	}

	getRect()'local rect { rect }

	setRect(rect_ : 'rect) {
		rect = copy rect_
		remaining = copy rect_
		for i (0 to children.size) {
			child : children[i]
			borderChild : child as #borderChild?
			position : borderChild?.getPosition()?:borderPosition.fill
			if position != borderPosition.fill {
				childSize : child.getSize(size(remaining.w, remaining.h))
				if position == borderPosition.left {
					child.setRect(rect(remaining.x, remaining.y, childSize.w, remaining.h))
					remaining = rect(remaining.x + childSize.w, remaining.y, remaining.w - childSize.w, remaining.h)
					void
				} else if position == borderPosition.right {
					child.setRect(rect(remaining.x + remaining.w - childSize.w, remaining.y, childSize.w, remaining.h))
					remaining = rect(remaining.x, remaining.y, remaining.w - childSize.w, remaining.h)
					void
				} else if position == borderPosition.top {
					child.setRect(rect(remaining.x, remaining.y, remaining.w, childSize.h))
					remaining = rect(remaining.x, remaining.y + childSize.h, remaining.w, remaining.h - childSize.h)
					void
				} else if position == borderPosition.bottom {
					child.setRect(rect(remaining.x, remaining.y + remaining.h - childSize.h, remaining.w, childSize.h))
					remaining = rect(remaining.x, remaining.y, remaining.w, remaining.h - childSize.h)
					void
				}
			}
		}	

		for i (0 to children.size) {
			child2 : children[i]
			borderChild2 : child2 as #borderChild?
			position2 : borderChild2?.getPosition()?:borderPosition.fill
			if position2 == borderPosition.fill {
				child2.setRect(remaining)
			}
		}	

		void	
	}

	render(scene : 'scene2d) {
		for i (0 to children.size) {
			child : children[i]
			child.render(scene)
		}
	}

	getChildren()'local array?!#element {
		a : local children
		value(a)
	}

	fireMouseEvent(point: 'point, eventId : 'i32)'void {
		for i (0 to children.size) {
			child : children[i]
			child.fireMouseEvent(point, eventId)
		}	
	}
) { this }