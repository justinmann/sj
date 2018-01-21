foo() { this }
bar() { foo() }
a : bar()
/*
global() { this }
child() { this }

global : global()

class(
    child : child()
    returnThisVar() {
        child
    }

    returnParentVar() {
        global
    }
) { this }

c : class()
d : c.returnThisVar()
e : c.returnParentVar()
*/