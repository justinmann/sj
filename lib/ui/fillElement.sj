fillElement #element (
	children : array!#element()
	rect = rect(0, 0, 0, 0)

	getRect()'local rect { rect }

	setRect(rect_ : 'rect) {
		rect = copy rect_
		for i (0 to children.size) {
			child : children[i]
			child.setRect(rect : rect)
		}	
		void	
	}

	render(scene : '#scene) {
		for i (0 to children.size) {
			child : children[i]
			child.render(scene)
		}
	}

	getChildren()'local array?!#element {
		a : local children
		value(a)
	}
) { this }