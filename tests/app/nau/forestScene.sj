forestBuyElement = heap fillLayout(
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

forestScene = heap nauScene3dElement(
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
                texture_fromPng("assets/leaf11.png")
                texture_fromPng("assets/leaf12.png")
                texture_fromPng("assets/leaf13.png")
                texture_fromPng("assets/leaf11.png")
                texture_fromPng("assets/leaf11.png")
                texture_fromPng("assets/leaf12.png")
                texture_fromPng("assets/leaf13.png")
            ]
        ) as #model

        heap peoplePanel(
            model : mat4_translate(vec3(0.0f, -1.3f, 0.0f))
            children : [
                heap scene2dModel(
                    id : valid("forest_person1")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person1")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson1.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("forest_person2")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person2")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson2.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("forest_person3")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person3")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson3.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("forest_person4")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person4")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson4.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("forest_person5")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person5")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson5.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("forest_person6")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person6")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson6.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("forest_person7")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person7")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson7.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model

                heap scene2dModel(
                    id : valid("forest_person8")
                    vertexBuffer : planeVertexBuffer()  
                    shader : copy phongTextureShader
                    hasAlpha : true
                    children : [
                        heap personElement(
                            id : valid("forest_person8")
                        ) as #element
                        heap imageElement(
                            image : image(texture : texture_fromPng("assets/forestperson8.png"))
                            stretch : imageStretch.aspectRatio
                        ) as #element
                    ]
                ) as #model
            ]
        ) as #model

        heap model(
            texture : texture_fromPng("assets/floor.png")
            shader : copy phongTextureShader
            model : mat4_translate(vec3(0.0f, -2.3f, 0.0f)) *  mat4_scale(40.0f, 40.0f, 40.0f) * mat4_rotate(90.0f, vec3(1.0f, 0.0f, 0.0f))
            vertexBuffer : planeVertexBuffer() 
        ) as #model

        heap panel3d(
            model : mat4_translate(vec3(0.0f, -1.3f, 0.0f))
            children : [
                heap model(
                    texture : texture_fromPng("assets/tree1.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(0.0f, 0.0f, 0.6f))
                    vertexBuffer : planeVertexBuffer(y1 : 6.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    texture : texture_fromPng("assets/tree3.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-2.0f, 0.0f, 2.3f))
                    vertexBuffer : planeVertexBuffer(y1 : 7.34f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    texture : texture_fromPng("assets/tree4.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-8.0f, 0.0f, 3.4f))
                    vertexBuffer : planeVertexBuffer(y1 : 9.18f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    texture : texture_fromPng("assets/tree3.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(9.0f, 0.0f, 2.3f))
                    vertexBuffer : planeVertexBuffer(y1 : 7.34f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    texture : texture_fromPng("assets/tree2.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-6.0f, 0.0f, 5.1f))
                    vertexBuffer : planeVertexBuffer(y1 : 7.0f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    texture : texture_fromPng("assets/tree3.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-7.5f, 0.0f, 6.3f))
                    vertexBuffer : planeVertexBuffer(y1 : 7.34f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    texture : texture_fromPng("assets/tree4.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(0.0f, 0.0f, 7.4f))
                    vertexBuffer : planeVertexBuffer(y1 : 9.18f) 
                    hasAlpha : true
                ) as #model

                heap model(
                    texture : texture_fromPng("assets/tree2.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-7.5f, 0.0f, 5.1f))
                    vertexBuffer : planeVertexBuffer(y1 : 7.0f) 
                    hasAlpha : true
                ) as #model
                
                heap model(
                    texture : texture_fromPng("assets/tree2.png")
                    shader : copy phongTextureShader
                    model : mat4_translate(vec3(-10.5f, 0.0f, 5.6f))
                    vertexBuffer : planeVertexBuffer(y1 : 7.0f) 
                    hasAlpha : true
                ) as #model
            ]
        ) as #model
    ]
)

forestElement = heap fillLayout(
    children : [
        forestScene as #element
        forestBuyElement as #element
        heap flowLayout(
            children : [
                heap buttonElement(
                    text : "back"
                    onClick : forestController.onBack
                ) as #element
            ]
        ) as #element
    ]
) as #element

forestTexture : texture_fromElement(forestElement, size(800, 352))