#gridChild(
    getRow()'i32
    getCol()'i32
)

gridChild #element #gridChild (
    row : 'i32
    col : 'i32
    child : 'heap #element
    _rect := rect()

    getRow() { row }
    getCol() { col }

    getSize(maxSize : 'size) {
        child.getSize(maxSize)
    }

    getRect()'rect { _rect }

    setRect(rect_ : 'rect) {
        _rect = rect_
        child.setRect(_rect)
        void    
    }

    render(scene : 'scene2d) {
        child.render(scene)
    }

    fireMouseEvent(mouseEvent : 'mouseEvent)'void {
        child.fireMouseEvent(mouseEvent)
    }
) { this }

enum gridUnitType(
    fixed
    star
)

gridUnit(
    amount : 1
    unitType : gridUnitType.star
) { this }

gridLayout #element (
    children : array!heap #element()
    margin := margin()
    cols := array!gridUnit()
    rows := array!gridUnit()
    _rect := rect()

    getSize(maxSize : 'size) {
        size(maxSize.w, maxSize.h)
    }

    getRect()'rect { _rect }

    setRect(rect_ : 'rect) {
        _rect = rect_
        innerRect : rect_ - margin

        rowFixed := 0
        rowStars := 0
        for r : 0 to rows.count {
            row : rows[r]
            if row.unitType == gridUnitType.star {
                rowStars += row.amount
            } else {
                rowFixed += row.amount
            }
        }

        rowStarUnit : if rowStars > 0 { (innerRect.h - rowFixed) / rowStars } else { 0 }
        rowStarRemainder := if rowStars > 0 { (innerRect.h - rowFixed) % rowStars } else { 0 }

        yPos : array!i32(rows.count + 1)
        y := innerRect.y
        yPos.initAt(0, y)
        for r : 0 to rows.count {
            row : rows[r]
            if row.unitType == gridUnitType.star {
                y += rowStarUnit * row.amount
                y += i32_max(0, rowStarRemainder)
                rowStarRemainder -= row.amount
            } else {
                y += row.amount
            }
            yPos.initAt(r + 1, y)
        }
            
        colFixed := 0
        colStars := 0
        for c : 0 to cols.count {
            col : cols[c]
            if col.unitType == gridUnitType.star {
                colStars += col.amount
            } else {
                colFixed += col.amount
            }
        }

        colStarUnit : if colStars > 0 { (innerRect.w - colFixed) / colStars } else { 0 }
        colStarRemainder := if colStars > 0 { (innerRect.w - colFixed) % colStars } else { 0 }

        xPos : array!i32(cols.count + 1)
        x := innerRect.x
        xPos.initAt(0, x)
        for c : 0 to cols.count {
            col : cols[c]
            if col.unitType == gridUnitType.star {
                x += colStarUnit * col.amount
                x += i32_max(0, colStarRemainder)
                colStarRemainder -= col.amount
            } else {
                x += col.amount
            }
            xPos.initAt(c + 1, x)
        }

        rNext := 0
        cNext := 0
        for i : 0 to children.count {           
            r := 0
            c := 0
            child : children[i]
            gridChild : child as heap #gridChild?
            ifValid gridChild {
                r = gridChild.getRow()
                c = gridChild.getCol()
                void
            } elseEmpty {
                r = rNext
                c = cNext
                cNext++
                if cNext >= cols.count {
                    cNext = 0
                    rNext++
                    if rNext >= rows.count {
                        rNext = 0
                    }
                }
                void
            }

            child.setRect(rect(
                xPos[c]
                yPos[r]
                xPos[c + 1] - xPos[c]
                yPos[r + 1] - yPos[r]
            ))
        }   

        void    
    }

    render(scene : 'scene2d) {
        for i : 0 to children.count {
            child : children[i]
            child.render(scene)
        }
    }

    fireMouseEvent(mouseEvent : 'mouseEvent) {
        mouseEvent.fireChildren(children)
    }
) { this }