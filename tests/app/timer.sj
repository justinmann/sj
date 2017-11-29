include "../../lib/common/common.sj"
include "../../lib/ui/ui.sj"

rootSurface : sdlSurface() as #surface
root : fillElement(
	children : [ 
		buttonElement(
			text = "Button Text"
		) as #element/*,
		imageElement(
			image : image(rootSurface.getTexture("assets/hello2.bmp"))
		) as #element,
		textElement(
			font = font("assets/sample.ttf", 25)
			text = "Bob"
			color = colors.red()
		) as #element*/
	]
) as #element

runLoop()