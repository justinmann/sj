fieldScene := heap nauScene3dElement()

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

/*                      person(
                    texture : texture_fromPng("assets/forestperson1.png")
                ) as #model

                person(
                    texture : texture_fromPng("assets/forestperson2.png")
                ) as #model

                person(
                    texture : texture_fromPng("assets/forestperson3.png")
                ) as #model

                person(
                    texture : texture_fromPng("assets/forestperson4.png")
                ) as #model

                person(
                    texture : texture_fromPng("assets/forestperson5.png")
                ) as #model

                person(
                    texture : texture_fromPng("assets/forestperson7.png")
                ) as #model

                person(
                    texture : texture_fromPng("assets/forestperson8.png")
                ) as #model */
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

fieldTexture : texture_fromElement(fieldScene as #element, size(800, 352))