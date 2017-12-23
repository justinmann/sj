mouse_captureElement := empty'heap #element

mouse_capture(element : 'heap #element) {
	mouse_captureElement = valid(element)
	--c--
	SDL_CaptureMouse(true);
	--c--
}

mouse_hasCapture(element : 'heap #element) {
	ifValid mouse_captureElement {
		mouse_captureElement === element
	} elseEmpty {
		false
	}
}

mouse_release(element : 'heap #element) {
	console.writeLine("release")
	ifValid m : mouse_captureElement {
	 	if m === element {
			console.writeLine("release done")
			mouse_captureElement = empty'#element
			--c--
			SDL_CaptureMouse(false);
			--c--
		}
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
	isLeftDown : 'bool

	fireChildren(children : 'array!heap #element) {
		shouldContinue := true
		for i : 0 toReverse children.count {
			if shouldContinue {
				child : children[i]
				shouldContinue = child.fireMouseEvent(parent)
			}
		}	
		shouldContinue
	}

	asString() {
		"point : " + point.asString() + " isCaptured : " + isCaptured.asString() + " isLeftDown : " + isLeftDown.asString()
	}
) { this }

