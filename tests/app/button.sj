include "lib/common/common.sj"
include "lib/ui/ui.sj"

controller(
    _button1Count := 0

    button1Clicked() {
        _button1Count++
        debug.writeLine("button1")

        ifValid button1Text : elementsById["button1Text"] {
            ifValid textElement : button1Text as #textElement? {
                textElement.text = "count : " + _button1Count.asString()
            }
        }
        void
    }
) { this }

rootController : heap controller()

root : heap gridLayout(
    margin : 10.asMargin()
    cols : [
        gridUnit(100, gridUnitType.fixed)
        gridUnit(1, gridUnitType.star)
    ]
    rows : [
        gridUnit(1, gridUnitType.star)
        gridUnit(1, gridUnitType.star)
        gridUnit(1, gridUnitType.star)
        gridUnit(1, gridUnitType.star)
    ]
    children : [
        heap buttonElement(
            text : "button1"
            onClick : rootController.button1Clicked
        ) as #element
        heap textElement(
            id : valid("button1Text")
            text : "bob"
            valign : textVertical.center
        ) as #element
    ]
) as #element

runLoop()