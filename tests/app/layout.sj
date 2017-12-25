include "lib/ui/ui.sj"

testElement(text : 'string) {
    heap fillLayout(
        children : [
            heap boxElement(
                color : color(f32_random(), f32_random(), f32_random())
                idealSize : size(i32_random() % 20 + 30, i32_random() % 20 + 30)
            ) as #element
            heap textElement(
                margin : margin(4, 4, 4, 4)
                text : copy text
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
        gridUnit(1, gridUnitType.star)
    ]
    rows : [
        gridUnit(1, gridUnitType.star)
        gridUnit(1, gridUnitType.star)
    ]
    children : [
        heap gridLayout(
            margin : margin(10, 10, 10, 10)
            rows : [
                gridUnit(50, gridUnitType.fixed)
                gridUnit(1, gridUnitType.star)
            ]
            cols : [
                gridUnit(1, gridUnitType.star)
                gridUnit(50, gridUnitType.fixed)
            ]
            children : [
                testElement("1")
                testElement("2")
                testElement("3")
                testElement("4")
            ]
        ) as #element

        heap borderLayout(
            margin : margin(10, 10, 10, 10)
            children : [
                heap borderChild(
                    position : borderPosition.left
                    child : testElement("left")
                ) as #element

                heap borderChild(
                    position : borderPosition.bottom
                    child : testElement("bottom")
                ) as #element

                heap borderChild(
                    position : borderPosition.top
                    child : testElement("top")
                ) as #element

                heap borderChild(
                    position : borderPosition.right
                    child : testElement("right")
                ) as #element

                heap borderChild(
                    position : borderPosition.fill
                    child : testElement("fill")
                ) as #element
            ]
        ) as #element

        heap listLayout(
            margin : margin(10, 10, 10, 10)
            children : [
                testElement("1")
                testElement("2")
                testElement("3")
                testElement("4")
            ]
        ) as #element

        heap flowLayout(
            margin : margin(10, 10, 10, 10)
            children : [
                testElement("1")
                testElement("2")
                testElement("3")
                testElement("4")
                testElement("1")
                testElement("2")
                testElement("3")
                testElement("4")
                testElement("1")
                testElement("2")
                testElement("3")
                testElement("4")
                testElement("1")
                testElement("2")
                testElement("3")
                testElement("4")
                testElement("1")
                testElement("2")
                testElement("3")
                testElement("4")
            ]
        ) as #element

        heap centerLayout(
            margin : margin(10, 10, 10, 10)
            centerX : valid(0.2f)
            centerY : valid(0.8f)
            children : [
                testElement("1")
            ]
        ) as #element
    ]
) as #element

runLoop()