mouse_captureElement := empty'heap #element

mouse_capture(element : 'heap #element) {
	mouse_captureElement = value(element)
	--c--
	SDL_CaptureMouse(true);
	--c--
}

mouse_release(element : 'heap #element) {
	console.writeLine("release")
	ifValue m : mouse_captureElement {
	 	// TODO: need to fix interface pointer comparison if m === element {
			console.writeLine("release done")
			mouse_captureElement = empty'#element
			--c--
			SDL_CaptureMouse(false);
			--c--
		// }
	}
	void
}

enum mouseEventType (
	move
	up
	down
)

mouseEvent(
	type : 'mouseEventType
	point : 'point
	isCaptured : 'bool
) { this }