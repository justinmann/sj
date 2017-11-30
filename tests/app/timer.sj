include "../../lib/common/common.sj"
include "../../lib/ui/ui.sj"

rootSurface : sdlSurface() as #surface
root : borderLayout(
	children : [
		borderChild(
			position : borderPosition.left
			child : buttonElement(
				text = "Button Text"
			) as #element
		) as #element
	]
) as #element

/*
fillElement(
	children : [ 
		imageElement(
			image : image(rootSurface.getTexture("assets/hello2.bmp"))
		) as #element,
		textElement(
			font = font("assets/sample.ttf", 25)
			text = "Bob"
			color = colors.red()
		) as #element
	]
) as #element
*/

runLoop()