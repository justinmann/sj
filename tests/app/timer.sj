include "../../lib/common/common.sj"
include "../../lib/ui/ui.sj"

/*
timerElement #element (
	counter = 0

	toHTML() {
		a : convert.i32toString(counter)
		b : "foo"
		b + a
	}

	onTick() {
		counter++
	}
) { 
	// timer.setTimer(100, onTick)
	this 
}

timerElement : timerElement()
*/

rootSurface : sdlSurface() as #surface
root : value(fillElement(
	children : [ 
		buttonElement() as #element,
		imageElement(
			image : image(rootSurface.getTexture("assets/hello2.bmp"))
		) as #element,
		textElement(
			font = font("assets/sample.ttf", 25)
			text = "Bob"
			color = colors.red()
		) as #element
	]
) as #element)

runLoop()