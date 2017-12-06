fireMouseUp(element :'#element, point: 'point) {
    mouseHandler : element as #mouseHandler?
    if element.getRect().containsPoint(point) {
        mouseHandler?.onMouseUp(point)
    }
    children : element.getChildren()
    if !isEmpty(children) {
        c : getValue(children)
        for i (0 to c.size) {
            fireMouseUp(c[i], point)
        }
    }
    void
}

fireMouseDown(element :'#element, point: 'point) {
    mouseHandler : element as #mouseHandler?
    if element.getRect().containsPoint(point) {
        mouseHandler?.onMouseDown(point)
    }
    children : element.getChildren()
    if !isEmpty(children) {
        c : getValue(children)
        for i (0 to c.size) {
            fireMouseDown(c[i], point)
        }
    }
    void
}