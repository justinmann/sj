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

	setRect(rect_ : 'rect) {
		rect = copy rect_
		child.setRect(rect : rect)
		void	
	}

	render(surface : '#surface) {
		child.render(surface)
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
	rect = rect(0, 0, 0, 0)

	setRect(rect_ : 'rect) {
		rect = copy rect_
		for i (0 to children.size) {
			child : children[i]
			child.setRect(rect : rect)
		}	
		void	
	}

	render(surface : '#surface) {
		for i (0 to children.size) {
			child : children[i]
			child.render(surface)
		}
	}

	getChildren()'local array?!#element {
		a : local children
		value(a)
	}
) { this }