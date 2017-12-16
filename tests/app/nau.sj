include "lib/common/common.sj"
include "lib/ui/ui.sj"
include "nau/nauScene3dElement.sj"
include "nau/leafPanel.sj"

root : fillElement(
	children : [
		nauScene3dElement(
			lookAtMin := vec3(-16.0f, -1.0f, 0.0f)
			lookAtMax := vec3(16.0f, 1.0f, 6.0f)
			children: [
                model(
                	texture : textureFromPng("assets/clouds.png")
                	shader : copy phongTextureShader
                	model : mat4_translate(0.0f, 0.0f, 20.0f) * mat4_scale(12.0f, 12.0f, 12.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -3.7f, y0 : -1.0f, x1 : 3.7f, y1 : 1.0f) 
                	hasAlpha : true
                ) as #model

				leafPanel(
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

				panel3d(
					model : mat4_translate(0.0f, -1.3f, 0.0f)
					children : [
		                model(
		                	id : "grass6.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(-8.6f, 0.0f, 6.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model


		                model(
		                	id : "grass6.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(8.6f, 0.0f, 6.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass4.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(-8.6f, 0.0f, 4.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass4.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(8.6f, 0.0f, 4.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass2.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(-9.6f, 0.0f, 2.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass2.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(7.6f, 0.0f, 2.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass0.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(-10.6f, 0.0f, 0.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass0.2"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(6.6f, 0.0f, 0.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass-1.8"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(-8.6f, 0.0f, -1.8f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model

		                model(
		                	id : "grass-1.8"
		                	texture : textureFromPng("assets/grass.png")
		                	shader : copy phongTextureShader
		                	model : mat4_translate(8.6f, 0.0f, -1.8f) * mat4_scale(2.0f, 2.0f, 2.0f)
		                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
		                	hasAlpha : true
		                ) as #model
					]
				) as #model


/*       
              <PeoplePanel Center="0.0, -1.3, 0.0" Control_Role="NAUSection!PeoplePanel" PeopleImages="{List('forestperson1', 'forestperson2', 'forestperson3', 'forestperson4', 'forestperson5', 'forestperson6', 'forestperson7', 'forestperson8')}" />
            <LeafPanel LeafImages="{List(Bitmap('whitestar1'), Bitmap('whitestar2'), Bitmap('whitestar1'), Bitmap('whitestar2'), Bitmap('whitestar1'), Bitmap('whitestar2'), Bitmap('whitestar1'), Bitmap('whitestar2'))}" />
*/
			]
		) as #element
		crossHairsElement(
			color : colors.red()
		) as #element
	]
) as #element

runLoop()