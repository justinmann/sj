fillElement #element (
	children : array!#element()
	rect = rect(0, 0, 0, 0)

	setRect(rect_ : 'rect) {
		console.write("setRect - 2")
		rect = copy rect_
		for i (0 to children.size) {
			child : children[i]
			child.setRect(rect : rect)
		}	
		void	
	}

	render(surface : '#surface) {
		console.write("render - 2")
		for i (0 to children.size) {
			child : children[i]
			child.render(surface)
		}
	}
) { this }