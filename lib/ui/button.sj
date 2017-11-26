button #element (
	text = ""
	font = style.getFont(0 /* TODO: typeId(button) */)
	rect = rect(0, 0, 0, 0)

	setRect(rect_ : 'rect) {
		rect = copy rect_
		void
	}

	render(surface : '#surface) {
		console.write("button - render - 1")
		// TODO: change color based on state
		// TODO: support nine-grid image background
		surface.fillRect(rect, color(255, 0, 0))
		// TODO: render text
		console.write("button - render - 2")
	}
) { 
	style.getFont(1)
	this 
}