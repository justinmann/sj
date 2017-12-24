fieldBuyElement = heap fillLayout(
    margin : margin(10, 100, 10, 10)
    effect : valid(heap fadeEffect(0.0f) as #effect)
    children : [
        heap borderLayout(
            children : [
                heap borderChild(
                    position : borderPosition.bottom
                    child : heap buttonElement(
                        text : "Buy me!"
                    ) as #element
                ) as #element
                heap borderChild(
                    position : borderPosition.right
                    child : heap fillLayout(
                        children : [
                            heap textElement(
                                idealSize : valid(size(250, 100))
                                text : "Product description"
                                color : copy colors.black
                            ) as #element
                        ]
                    ) as #element
                ) as #element
            ]
        ) as #element
    ]
)

fieldScene = heap nauScene3dElement(
    lookAtMin := vec3(-16.0f, -1.0f, 0.0f)
    lookAtMax := vec3(16.0f, 1.0f, 6.0f)
    children: [
        heap model(
            texture : texture_fromPng("assets/forest_backdrop.png")
            shader : copy phongTextureShader
            model : mat4_translate(vec3(0.0f, 8.0f, 20.0f)) * mat4_scale(12.0f, 12.0f, 12.0f)
            vertexBuffer : planeVertexBuffer(x0 : -6.3f, y0 : -1.0f, x1 : 6.3f, y1 : 1.0f) 
        ) as #model

        heap leafPanel(
            textures : [
                texture_fromPng("assets/whitestar1.png")
                texture_fromPng("assets/whitestar2.png")
                texture_fromPng("assets/whitestar1.png")
                texture_fromPng("assets/whitestar2.png")
                texture_fromPng("assets/whitestar1.png")
                texture_fromPng("assets/whitestar2.png")
                texture_fromPng("assets/whitestar1.png")
                texture_fromPng("assets/whitestar2.png")
            ]
        ) as #model

        heap peoplePanel(
            model : mat4_translate(vec3(0.0f, 0.0f, 0.0f))
            children : [
                heap scene2dModel(
                    id : valid("person1")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person1")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson1.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("person2")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person2")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson2.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("person3")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person3")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson3.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("person4")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person4")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson4.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("person5")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person5")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson5.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("person6")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person6")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson6.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("person7")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person7")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson7.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("person8")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("person8")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson8.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model
            ]
        ) as #model

        heap panel3d(
            model : mat4_translate(vec3(0.0f, -1.3f, 0.0f))
            children : [
                heap model(
                    id : valid("grass6.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-8.6f, 0.0f, 6.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model


                heap model(
                    id : valid("grass6.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(8.6f, 0.0f, 6.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass4.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-8.6f, 0.0f, 4.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass4.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(8.6f, 0.0f, 4.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass2.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-9.6f, 0.0f, 2.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass2.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(7.6f, 0.0f, 2.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass0.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-10.6f, 0.0f, 0.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass0.2")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(6.6f, 0.0f, 0.2f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass-1.8")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-8.6f, 0.0f, -1.8f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    id : valid("grass-1.8")
                    texture : texture_fromPng("assets/grass.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(8.6f, 0.0f, -1.8f)) * mat4_scale(2.0f, 2.0f, 2.0f)
                    vertexBuffer : planeVertexBuffer(x0 : -4.3f, y0 : -1.0f, x1 : 4.3f, y1 : 1.0f) 
                    hasAlpha : true
                ) as #model
            ]
        ) as #model
    ]
)

fieldElement = heap fillLayout(
    children : [
        fieldScene as #element
        fieldBuyElement as #element
        heap flowLayout(
            children : [
                heap buttonElement(
                    text : "back"
                    onClick : fieldController.onBack
                ) as #element
            ]
        ) as #element
    ]
) as #element

fieldTexture : texture_fromElement(fieldElement, size(800, 352))