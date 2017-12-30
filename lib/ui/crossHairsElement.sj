crossHairsElement #element (
    color := colors.white
    _rect := rect()
    _topDownRenderer := empty'boxRenderer
    _leftRightRenderer := empty'boxRenderer
    _point := point()

    getSize(maxSize : 'size) {
        size(maxSize.w, maxSize.h)
    }

    getRect()'rect { _rect }

    setRect(rect_ : 'rect)'void {
        if _rect != rect_ {
            _rect = rect_
            _topDownRenderer = empty'boxRenderer
            _leftRightRenderer = empty'boxRenderer
        }
        void
    }

    render(scene : 'scene2d)'void {
        if isEmpty(_topDownRenderer) {
            _topDownRenderer = valid(boxRenderer(
                rect: rect(_point.x, _rect.y, 1, _rect.h)
                color: color))
        }

        if isEmpty(_leftRightRenderer) {
            _leftRightRenderer = valid(boxRenderer(
                rect: rect(_rect.x, _point.y, _rect.w, 1)
                color: color))
        }

        _topDownRenderer?.render(scene)
        _leftRightRenderer?.render(scene)
    }

    fireMouseEvent(mouseEvent : 'mouseEvent)'bool {
        if _rect.containsPoint(mouseEvent.point) {
            if mouseEvent.eventType == mouseEventType.move {
                _point = mouseEvent.point
                _topDownRenderer = empty'boxRenderer
                _leftRightRenderer = empty'boxRenderer
            }
        }
        true
    }
) { this }