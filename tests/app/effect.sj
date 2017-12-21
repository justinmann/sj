include "lib/common/common.sj"
include "lib/ui/ui.sj"

testScene() {
	heap fillLayout(
		children : [
			heap boxElement(
				color : color(f32_random(), f32_random(), f32_random())
			) as #element
		
			heap scene3dElement(
				children : [
					heap model(
						vertexBuffer : sphereVertexBuffer()
						shader : copy phongTextureShader
						texture : textureFromPng("assets/cat.png")
					) as #model
				]
			) as #element	

			heap textElement(
				text : "Hello"
				halign : textHorizontal.center
				valign : textVertical.center
				color : copy colors.white
			) as #element
		]
	) as #element
}

root : heap gridLayout(
	cols : [
		gridUnit(1, gridUnitType.star)
		gridUnit(1, gridUnitType.star)
	]
	rows : [
		gridUnit(1, gridUnitType.star)
		gridUnit(1, gridUnitType.star)
	]
	children : [

		heap fillLayout(
			margin : margin(10, 10, 10, 10)
			children : [
				testScene()
			]
		) as #element

		heap fillLayout(
			margin : margin(10, 10, 10, 10)
			effect : valid(heap blurEffect(0.5f) as #effect)
			children : [
				testScene()
			]
		) as #element

		heap fillLayout(
			margin : margin(10, 10, 10, 10)
			effect : valid(heap fadeEffect(0.5f) as #effect)
			children : [
				testScene()
			]
		) as #element
	]
) as #element

runLoop()