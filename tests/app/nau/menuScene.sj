menuScene = heap nauScene3dElement(
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
                            texture : texture_fromPng("assets/menu1.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu2.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu3.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu4.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu5.png")
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
                            texture : texture_fromPng("assets/menu6.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu7.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu8.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu9.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu10.png")
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
                            texture : texture_fromPng("assets/menu3.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu4.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu5.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu6.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu7.png")
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
                            texture : texture_fromPng("assets/menu11.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(-2.2f, 0.0f, 1.8f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu12.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu1.png")
                            shader : copy phongTextureShader
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                        ) as #model

                        heap model(
                            texture : texture_fromPng("assets/menu2.png")
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
                            textureSize : size(800, 352)
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                            children : [
                                heap imageElement(
                                    image : image(texture : texture_fromPng("assets/menu8.png"))
                                ) as #element

                                heap centerLayout(
                                    margin : margin(20, 20, 20, 20)
                                    centerX : valid(0.1f)
                                    centerY : valid(0.9f)
                                    children: [
                                        heap listLayout(
                                            orientation : listLayoutOrientation.topBottom
                                            children: [
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 30.0f)
                                                    text : "womens"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 50.0f)
                                                    text : "pants/shorts"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                            ]
                                        ) as #element
                                    ]
                                ) as #element
                            ]
                        ) as #model

                        heap scene2dModel(
                            id : valid("forestMenu")
                            shader : copy phongTextureShader
                            textureSize : size(800, 352)
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            children : [
                                heap imageElement(
                                    image : image(texture : copy forestTexture)
                                ) as #element

                                heap buttonElement(
                                    normalImage : empty'image
                                    hotImage : empty'image
                                    pressedImage : empty'image
                                    onClick : valid(menuController.viewForestMenu)
                                ) as #element

                                heap centerLayout(
                                    margin : margin(20, 20, 20, 20)
                                    centerX : valid(1.0f)
                                    centerY : valid(1.0f)
                                    children: [
                                        heap listLayout(
                                            orientation : listLayoutOrientation.topBottom
                                            children: [
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 30.0f)
                                                    text : "mens"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 50.0f)
                                                    text : "forest collection"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                            ]
                                        ) as #element
                                    ]
                                ) as #element
                            ]
                        ) as #model
                        
                        heap scene2dModel(
                            shader : copy phongTextureShader
                            textureSize : size(800, 352)
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            hasAlpha : true
                            children : [
                                heap imageElement(
                                    image : image(texture : texture_fromPng("assets/menu9.png"))
                                ) as #element

                                heap centerLayout(
                                    margin : margin(20, 20, 20, 20)
                                    centerX : valid(1.0f)
                                    centerY : valid(0.65f)
                                    children: [
                                        heap listLayout(
                                            orientation : listLayoutOrientation.topBottom
                                            children: [
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 30.0f)
                                                    text : "womens"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 50.0f)
                                                    text : "pants/shorts"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                            ]
                                        ) as #element
                                    ]
                                ) as #element
                            ]
                        ) as #model

                        heap scene2dModel(
                            id : valid("fieldMenu")
                            shader : copy phongTextureShader
                            textureSize : size(800, 352)
                            model : mat4_translate(vec3(1.5f, 0.0f, 0.5f))
                            vertexBuffer : planeVertexBuffer(x0 : -1.4f, y0 : -0.6f, x1 : 1.4f, y1 : 0.6f) 
                            children : [
                                heap imageElement(
                                    image : image(texture : copy fieldTexture)
                                ) as #element

                                heap buttonElement(
                                    normalImage : empty'image
                                    hotImage : empty'image
                                    pressedImage : empty'image
                                    onClick : valid(menuController.viewFieldMenu)
                                ) as #element

                                heap centerLayout(
                                    margin : margin(20, 20, 20, 20)
                                    centerX : valid(1.0f)
                                    centerY : valid(1.0f)
                                    children: [
                                        heap listLayout(
                                            orientation : listLayoutOrientation.topBottom
                                            children: [
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 30.0f)
                                                    text : "mens"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                                heap textElement(
                                                    font : font_load("assets/arial.ttf", 50.0f)
                                                    text : "field collection"
                                                    halign : textHorizontal.right
                                                    color : copy colors.white
                                                ) as #element
                                            ]
                                        ) as #element
                                    ]
                                ) as #element
                            ]
                        ) as #model
                    ]
                ) as #model
            ]
        ) as #model
    ]
)

menuElement = heap fillLayout(
    children : [
        heap boxElement(
            color : copy colors.black
        ) as #element
        heap menuScene as #element
    ]
) as #element

menuController.start()