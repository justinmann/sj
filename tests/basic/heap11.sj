inner() { this }

class(
    inner : inner()
) { this }

class2(
    inner : valid(inner())
) { this }

x3'stack class? : valid(class())
x7'stack class2? : valid(class2())
