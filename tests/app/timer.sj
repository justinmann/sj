include "lib/ui/ui.sj"

root : heap fillLayout(
    children : [
        heap scene3dElement(
            children: [
                heap scene2dModel(
                    vertexBuffer : sphereVertexBuffer()
                    shader : phongTextureShader
                    children : [
                        heap imageElement(
                            image : image(texture_fromPng("assets/test.png"), margin: margin(150, 50, 150, 150))
                        ) as #element
                        heap crossHairsElement(
                            color : colors.blue
                        ) as #element
                    ]
                ) as #model
            ]
        ) as #element
        heap crossHairsElement(
            color : colors.red
        ) as #element
    ]
) as #element
/*
root : blurElement(
    children : [
        imageElement(
            image : image(texture_fromPng("assets/test.png"), margin: margin(150, 50, 150, 150))
        ) as #element
    ]
) as #element
*/
/*
root : textElement(
    font = font("assets/sample.ttf", 25.0f)
    text = "Bob"
    color = colors.red()
) as #element
*/

/*
root : borderLayout(
    children : [
        borderChild(
            position : borderPosition.left
            child : buttonElement(
                text = "Button Text"
            ) as #element
        ) as #element,
        borderChild(
            position : borderPosition.right
            child : boxElement(
                color = colors.red()
                idealSize = size(50, i32_maxValue)
            ) as #element
        ) as #element,
        boxElement(
            color = colors.green()
        ) as #element
    ]
) as #element
*/
/*
fillLayout(
    children : [ 
        imageElement(
            image : image(rootscene.getTexture("assets/hello2.bmp"))
        ) as #element,
        textElement(
            font = font("assets/sample.ttf", 25)
            text = "Bob"
            color = colors.red()
        ) as #element
    ]
) as #element
*/

runLoop()