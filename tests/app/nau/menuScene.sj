menuScene() {
    result : heap nauScene3dElement(
        lookAtMin := vec3(-7.0f, -1.0f, 0.0f)
        lookAtMax := vec3(7.0f, 1.0f, 50.0f)
        children: [
            heap panel3d(
                children : [
                    heap mainPanel(
                        model : mat4_translate(vec3(0.0f, -2.0f, 1.8f))
                        radius : 57.0f
                        children : [
                            heap model(
                                texture : textureFromPng("assets/menu1.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu2.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu3.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu4.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu5.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model
                        ]
                    ) as #model

                    heap mainPanel(
                        model : mat4_translate(vec3(0.0f, -0.4f, 0.0f))
                        radius : 56.0f
                        children : [
                            heap model(
                                texture : textureFromPng("assets/menu6.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu7.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu8.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu9.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu10.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model
                        ]
                    ) as #model                    

                    heap mainPanel(
                        model : mat4_translate(vec3(0.0f, 2.0f, 0.0f))
                        radius : 55.0f
                        children : [
                            heap model(
                                texture : textureFromPng("assets/menu3.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu4.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu5.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu6.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu7.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model
                        ]
                    ) as #model                    

                    heap mainPanel(
                        model : mat4_translate(vec3(0.0f, 0.4f, 0.0f))
                        radius : 54.0f
                        children : [
                            heap model(
                                texture : textureFromPng("assets/menu11.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu12.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu1.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu2.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model
                        ]
                    ) as #model    

                    heap mainPanel(
                        model : mat4_translate(vec3(0.0f, -1.0f, 0.0f))
                        radius : 50.0f
                        children : [
                            heap scene2dModel(
                                shader : copy phongTextureShader
                                textureSize : size(200, 88)
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                                children : [
                                    heap imageElement(
                                        image : image(texture : textureFromPng("assets/menu8.png"))
                                    ) as #element
                                    heap textElement(
                                        font : font("assets/sample.ttf", 15.0f)
                                        text : "womens"
                                        color : colors.red()
                                    ) as #element
                                ]
                            ) as #model
/*
                            heap model(
                                texture : textureFromPng("assets/menu12.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu1.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model

                            heap model(
                                texture : textureFromPng("assets/menu2.png")
                                shader : copy phongTextureShader
                                model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                                vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                                hasAlpha : true
                            ) as #model
*/
                        ]
                    ) as #model
                ]
            ) as #model
/*

        <Panel3D Control_Role="NAUSection!MainPanel">
          <MainPanel Center="0.0, -1.0, 0.0" Radius="50.0">
            <Model CacheContentAsTexture="True" Center="1.5, 0.0, 0.5" ContentSize="200, 88" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-1.4, -0.6, 1.4, 0.6)}">
              <Image Bitmap="{Bitmap('menu8')}" />
              <CenterPanel CenterX="0.1" CenterY="0.9">
                <ListPanel>
                  <Text Content="womens" FontColor="#ffffff" FontSize="15" />
                  <Text Content="pants/shorts" FontColor="#ffffff" FontSize="25" />
                </ListPanel>
              </CenterPanel>
            </Model>
            <Model CacheContentAsTexture="True" Center="1.5, 0.0, 0.5" ContentSize="200, 88" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-1.4, -0.6, 1.4, 0.6)}">
              <Image Bitmap="{Bitmap('menu9')}" />
              <CenterPanel CenterX="1.0" CenterY="0.65">
                <ListPanel>
                  <Text Content="womens" FontColor="#ffffff" FontSize="15" HorizontalAlignment="Right" />
                  <Text Content="pants/shorts" FontColor="#ffffff" FontSize="25" />
                </ListPanel>
              </CenterPanel>
            </Model>
            <Model CacheContentAsTexture="True" Center="-2.2, 0.0, 1.8" ContentSize="200, 88" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-1.4, -0.6, 1.4, 0.6)}">
                <NAUSection OnClick="{ControlRoot.NAUSection!ZoomIn(this)}" Template="{Template('PeopleSection1')}" />
                <CenterPanel CenterX="1.0" CenterY="1.0">
                    <ListPanel>
                        <Text Content="mens" FontColor="#ffffff" FontSize="15" HorizontalAlignment="Right" />
                        <Text Content="autumn collection" FontColor="#ffffff" FontSize="25" />
                    </ListPanel>
                </CenterPanel>
            </Model>
        </MainPanel>
        <MainPanel Center="0.0, 1.0, 0.0" Radius="50.0">
            <Model CacheContentAsTexture="True" Center="1.5, 0.0, 0.5" ContentSize="200, 88" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-1.4, -0.6, 1.4, 0.6)}">
              <NAUSection OnClick="{ControlRoot.NAUSection!ZoomIn(this)}" Template="{Template('PeopleSection2')}" />
              <CenterPanel CenterX="0.1" CenterY="0.65">
                <ListPanel>
                  <Text Content="womens" FontColor="#ffffff" FontSize="15" />
                  <Text Content="pants/shorts" FontColor="#ffffff" FontSize="25" />
                </ListPanel>
              </CenterPanel>
              <CrossHairs />
            </Model>
            <Model CacheContentAsTexture="True" Center="1.5, 0.0, 0.5" ContentSize="200, 88" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-1.4, -0.6, 1.4, 0.6)}">
              <Image Bitmap="{Bitmap('menu10')}" />
              <CenterPanel CenterX="0.1" CenterY="0.0">
                <ListPanel>
                  <Text Content="womens" FontColor="#ffffff" FontSize="15" />
                  <Text Content="pants/shorts" FontColor="#ffffff" FontSize="25" />
                </ListPanel>
              </CenterPanel>
            </Model>
            <Model CacheContentAsTexture="True" Center="1.5, 0.0, 0.5" ContentSize="200, 88" HasAlpha="True" Mesh="{Mesh!CreateRectangle(-1.4, -0.6, 1.4, 0.6)}">
              <Image Bitmap="{Bitmap('menu11')}" />
              <CenterPanel CenterX="0.1" CenterY="1.0">
                <ListPanel>
                  <Text Content="womens" FontColor="#ffffff" FontSize="15" />
                  <Text Content="pants/shorts" FontColor="#ffffff" FontSize="25" />
                </ListPanel>
              </CenterPanel>
            </Model>
          </MainPanel>
          <BubblePanel Bitmap="{Bitmap('bubbles_atmosphere')}" Effect="{FadeEffect(0.5)}" Radius="52.1" />
          <BubblePanel Bitmap="{Bitmap('bubbles_atmosphere')}" Effect="{FadeEffect(0.5)}" Height="15.0" Offset="0.2" Radius="62.0" Slices="30.0" />
        </Panel3D>

*/
        ]
    )

    result.animateLookAt(vec3(0.0f, 0.0f, 50.0f), 5000)

    result
}