fillElement #element (
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