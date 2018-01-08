
class(x: 0) { this }
a : array.create!class(1, class())
a.setAt(0, class(1))
b : a.getAt(0)
c : b.x
c