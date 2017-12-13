include "lib/common/common.sj"
include "lib/ui/ui.sj"

root : fillElement(
	children : [
		scene3dElement(
			children: [
/*
<Panel3D Control_Role="NAUSection!MainPanel">
              <Model Bitmap="{Bitmap('clouds')}" Center="0.0, 0.0, 20.0" Mesh="{Mesh!CreateRectangle(-3.7, -1.0, 3.7, 1.0)}" Scale="12.0" />
              <Panel3D Center="0.0, -1.3, 0.0">
              */
                model(
                	texture : textureFromPng("assets/grass.png")
                	shader : copy phongTextureShader
                	world : mat4_translate(-8.6f, 0.0f, 6.2f) * mat4_scale(2.0f, 2.0f, 2.0f)
                	vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                	) as #model

/*       
                 <Model Bitmap="{Bitmap('grass')}" Center="8.6, 0.0, 6.2" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                <Model Bitmap="{Bitmap('grass')}" Center="-8.6, 0.0, 4.2" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                  <Model Bitmap="{Bitmap('grass')}" Center="8.6, 0.0, 4.2" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                  <Model Bitmap="{Bitmap('grass')}" Center="-9.6, 0.0, 2.2" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                  <Model Bitmap="{Bitmap('grass')}" Center="7.6, 0.0, 2.2" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                  <Model Bitmap="{Bitmap('grass')}" Center="-10.6, 0.0, 0.2" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                  <Model Bitmap="{Bitmap('grass')}" Center="6.6, 0.0, 0.2" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                <Model Bitmap="{Bitmap('grass')}" Center="-8.6, 0.0, -1.8" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
                <Model Bitmap="{Bitmap('grass')}" Center="8.6, 0.0, -1.8" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-4.3, -1.0, 4.3, 1.0)}" Scale="2.0" />
              </Panel3D>
              <PeoplePanel Center="0.0, -1.3, 0.0" Control_Role="NAUSection!PeoplePanel" PeopleImages="{List('forestperson1', 'forestperson2', 'forestperson3', 'forestperson4', 'forestperson5', 'forestperson6', 'forestperson7', 'forestperson8')}" />
            <LeafPanel LeafImages="{List(Bitmap('whitestar1'), Bitmap('whitestar2'), Bitmap('whitestar1'), Bitmap('whitestar2'), Bitmap('whitestar1'), Bitmap('whitestar2'), Bitmap('whitestar1'), Bitmap('whitestar2'))}" />
          </Panel3D>
*/
			]
		) as #element
		crossHairsElement(
			color : colors.red()
		) as #element
	]
) as #element

runLoop()