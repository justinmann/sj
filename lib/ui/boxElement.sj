boxElement #element (
    color := colors.white
    idealSize := size()
    rect := rect()
    boxRenderer := empty'boxRenderer

    getSize(maxSize : 'size) {
        idealSize.min(maxSize)
    }

    getRect()'rect { rect }

    setRect(rect_ : 'rect)'void {
        if rect != rect_ {
            rect = rect_
            boxRenderer = empty'boxRenderer
        }
        void
    }

    render(scene : 'scene2d)'void {
        if isEmpty(boxRenderer) {
            boxRenderer = valid(boxRenderer(
                rect: rect
                color: color))
        }

        boxRenderer?.render(scene)
    }

    fireMouseEvent(mouseEvent : 'mouseEvent)'bool { }
) { this }