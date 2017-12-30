@heap
personElement #element #clickable (
    id : empty'string
    _rect := rect()
    _clickGesture := clickGesture() // TODO:

    getSize(maxSize : 'size) { maxSize }

    getRect()'rect { _rect }
    setRect(r : 'rect) {
        if _rect != r {
            _rect = r
            _clickGesture.rect = r
        }
        void
    }

    render(scene : 'scene2d) {
        void
    }

    onClickGestureEnter(element : '#element) { void }
    onClickGestureLeave(element : '#element) { void }
    onClickGesturePress(element : '#element) { void }
    onClickGestureClick(element : '#element) { 
        log.trace(parent.type, ^{ "clicked" })
        ifValid id {
            fieldController.selectPerson(id)
            forestController.selectPerson(id)
        }
        void 
    }

    fireMouseEvent(mouseEvent : 'mouseEvent) {
        log.trace(parent.type, ^{ mouseEvent.asString() })
        _clickGesture.fireMouseEvent(mouseEvent)
    }
) { 
    _clickGesture = clickGesture(this as #element, this as #clickable)
    this 
}