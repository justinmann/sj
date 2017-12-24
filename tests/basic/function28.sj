vec3() { this }
vec2() { this }

vertex_location_texture_normal(
    location : vec3()
    texture : vec2()
    normal : vec3()
) { this }

t : vec3()

a : vertex_location_texture_normal(
    location : vec3()
    texture : copy t
    normal : vec3()
)