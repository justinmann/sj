@heap
personElement #element #clickable (
    id : empty'string
    _rect := rect()
    _clickGesture := clickGesture() // TODO:

    getSize(maxSize : 'size) { copy maxSize }

    getRect()'rect { copy _rect }
    setRect(r : 'rect) {
        if _rect != r {
            _rect = copy r
            _clickGesture.rect = copy r
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
        ifValid id {
            fieldController.selectPerson(id)
            forestController.selectPerson(id)
        }
        void 
    }

    fireMouseEvent(mouseEvent : 'mouseEvent) {
        _clickGesture.fireMouseEvent(mouseEvent)
    }
) { 
    _clickGesture = copy clickGesture(this as #element, this as #clickable)
    this 
}