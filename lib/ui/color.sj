package colors {
    red : color(1.0f, 0.0f, 0.0f)
    green : color(0.0f, 1.0f, 0.0f)
    blue : color(0.0f, 0.0f, 1.0f)
    black : color(0.0f, 0.0f, 0.0f)
    white : color(1.0f, 1.0f, 1.0f)
    gray : color(0.5f, 0.5f, 0.5f)
}

color(
    r : 'f32
    g : 'f32
    b : 'f32
    a : 1.0f

    asString() {
        "r: " + r.asString() + "g: " + g.asString() + "b: " + b.asString() + "a: " + a.asString()
    }

    asVec3() {
        vec3(r, g, b)
    }

    asVec4() {
        vec4(r, g, b, a)
    }
) { this }