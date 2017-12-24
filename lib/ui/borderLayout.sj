enum borderPosition (
    fill
    left
    right
    top
    bottom 
)

#borderChild(
    getPosition()'borderPosition
)

borderChild #element #borderChild (
    child : 'heap #element
    position := borderPosition.fill
    _rect := rect()

    getPosition() { position }

    getSize(maxSize : 'size) {
        child.getSize(maxSize)
    }

    getRect()'rect { copy _rect }

    setRect(rect_ : 'rect) {
        _rect = copy rect_
        child.setRect(_rect)
        void    
    }

    render(scene : 'scene2d) {
        child.render(scene)
    }

    fireMouseEvent(mouseEvent : 'mouseEvent)'bool {
        child.fireMouseEvent(mouseEvent)
    }
) { this }

borderLayout #element (
    children : array!heap #element()
    margin := margin()
    _rect := rect()

    getSize(maxSize : 'size) {
        size(maxSize.w, maxSize.h)
    }

    getRect()'rect { copy _rect }

    setRect(rect_ : 'rect) {
        _rect = copy rect_
        remaining := rect_ - margin
        for i : 0 to children.count {
            child : children[i]
            borderChild : child as heap #borderChild?
            position : borderChild?.getPosition()?:(borderPosition.fill)

            if position != borderPosition.fill {
                childSize : child.getSize(size(remaining.w, remaining.h))
                if position == borderPosition.left {
                    child.setRect(rect(remaining.x, remaining.y, childSize.w, remaining.h))
                    remaining = rect(remaining.x + childSize.w, remaining.y, remaining.w - childSize.w, remaining.h)
                    void
                } else if position == borderPosition.right {
                    child.setRect(rect(remaining.x + remaining.w - childSize.w, remaining.y, childSize.w, remaining.h))
                    remaining = rect(remaining.x, remaining.y, remaining.w - childSize.w, remaining.h)
                    void
                } else if position == borderPosition.top {
                    child.setRect(rect(remaining.x, remaining.y, remaining.w, childSize.h))
                    remaining = rect(remaining.x, remaining.y + childSize.h, remaining.w, remaining.h - childSize.h)
                    void
                } else if position == borderPosition.bottom {
                    child.setRect(rect(remaining.x, remaining.y + remaining.h - childSize.h, remaining.w, childSize.h))
                    remaining = rect(remaining.x, remaining.y, remaining.w, remaining.h - childSize.h)
                    void
                }
            }
        }   

        for i : 0 to children.count {
            child2 : children[i]
            borderChild2 : child2 as heap #borderChild?
            position2 : borderChild2?.getPosition()?:(borderPosition.fill)
            if position2 == borderPosition.fill {
                child2.setRect(remaining)
            }
        }   

        void    
    }

    render(scene : 'scene2d) {
        for i : 0 to children.count {
            child : children[i]
            child.render(scene)
        }
    }

    fireMouseEvent(mouseEvent : 'mouseEvent)'bool {
        mouseEvent.fireChildren(children)
    }
) { this }