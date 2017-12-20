include "lib/common/common.sj"
include "lib/ui/ui.sj"
include "nau/nauScene3dElement.sj"
include "nau/leafPanel.sj"
include "nau/peoplePanel.sj"
include "nau/personElement.sj"

nauScene : heap nauScene3dElement(
	lookAtMin := vec3(-16.0f, -1.0f, 0.0f)
	lookAtMax := vec3(16.0f, 1.0f, 6.0f)
	children: [
        heap model(
        	texture : textureFromPng("assets/forest_backdrop.png")
        	shader : copy phongTextureShader
        	model : mat4_translate(0.0f, 8.0f, 20.0f) * mat4_scale(12.0f, 12.0f, 12.0f)
        	vertexBuffer : planeVertexBuffer(x0 : -6.3f, y0 : -1.0f, x1 : 6.3f, y1 : 1.0f) 
        ) as #model

		heap leafPanel(
			textures : [
				textureFromPng("assets/whitestar1.png")
				textureFromPng("assets/whitestar2.png")
				textureFromPng("assets/whitestar1.png")
				textureFromPng("assets/whitestar2.png")
				textureFromPng("assets/whitestar1.png")
				textureFromPng("assets/whitestar2.png")
				textureFromPng("assets/whitestar1.png")
				textureFromPng("assets/whitestar2.png")
			]
		) as #model

		heap peoplePanel(
			model : mat4_translate(0.0f, 0.0f, 0.0f)
			children : [
				heap scene2dModel(
					id : valid("person1")
					vertexBuffer : planeVertexBuffer()  
                	shader : copy phongTextureShader
					children : [
						heap personElement(
							id : valid("person1")
						) as #element
						heap boxElement(
							color : colors.red()
						) as #element
						heap imageElement(
							image : image(texture : textureFromPng("assets/forestperson1.png"))
							stretch : imageStretch.aspectRatio
						) as #element
						heap crossHairsElement(
							color : colors.blue()
						) as #element
					]
				) as #model

				heap scene2dModel(
					id : valid("person2")
					vertexBuffer : planeVertexBuffer()  
                	shader : copy phongTextureShader
					children : [
						heap personElement(
							id : valid("person2")
						) as #element
						heap boxElement() as #element
						heap imageElement(
							image : image(texture : textureFromPng("assets/forestperson2.png"))
							stretch : imageStretch.aspectRatio
						) as #element
						heap crossHairsElement(
							color : colors.green()
						) as #element
					]
				) as #model

/*						person(
					texture : textureFromPng("assets/forestperson1.png")
				) as #model

				person(
					texture : textureFromPng("assets/forestperson2.png")
				) as #model

				person(
					texture : textureFromPng("assets/forestperson3.png")
				) as #model

				person(
					texture : textureFromPng("assets/forestperson4.png")
				) as #model

				person(
					texture : textureFromPng("assets/forestperson5.png")
				) as #model

				person(
					texture : textureFromPng("assets/forestperson7.png")
				) as #model

				person(
					texture : textureFromPng("assets/forestperson8.png")
				) as #model */
			]
		) as #model

		heap panel3d(
			model : mat4_translate(0.0f, -1.3f, 0.0f)
			children : [
                heap model(
                	id : valid("grass6.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(-8.6f, 0.0f, 6.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model


                heap model(
                	id : valid("grass6.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(8.6f, 0.0f, 6.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass4.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(-8.6f, 0.0f, 4.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass4.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(8.6f, 0.0f, 4.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass2.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(-9.6f, 0.0f, 2.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass2.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(7.6f, 0.0f, 2.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass0.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(-10.6f, 0.0f, 0.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass0.2")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(6.6f, 0.0f, 0.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass-1.8")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(-8.6f, 0.0f, -1.8f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

                heap model(
                	id : valid("grass-1.8")
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(8.6f, 0.0f, -1.8f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model
			]
		) as #model
	]
)

root : fillElement(
	children : [
		heap nauScene as #element
		heap crossHairsElement(
			color : colors.red()
		) as #element
	]
) as #element

runLoop()