buttonElement #element (
	text = ""
	font = style.getFont(0 /* TODO: typeId(button) */)
	rect = rect(0, 0, 0, 0)
	offset = 0

	setRect(rect_ : 'rect) {
		rect = copy rect_
		void
	}

	render(surface : '#surface) {
		// TODO: change color based on state
		// TODO: support nine-grid image background
		surface.fillRect(rect(rect.x, rect.y + offset, rect.w, rect.h - 2 * offset), color(255, 0, 0))
		// TODO: render text
		offset++
		void
	}
) { 
	style.getFont(1)
	this 
}