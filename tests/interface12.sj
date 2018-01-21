
#bar(
    getX()'i32
)

foo #bar (
    getX() { 0 }
) { this }

a : heap foo()
b : a as #bar