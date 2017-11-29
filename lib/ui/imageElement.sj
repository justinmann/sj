imageElement #element (
	image = 'image
	rect = rect()

	setRect(rect_ : 'rect)'void {
		rect = copy rect_.addMargin(10, 10, 10, 10)
		void
	}

	render(surface : '#surface)'void {
		surface.drawImage(rect, image)
	}
) { this }