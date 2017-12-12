vertex_location_texture_normal_format : "vertex:3f,tex_coord:2f,normal:3f"
vertex_location_texture_normal(
    location : vec3()
    texture : vec2()
    normal : vec3()
) { this }

cubeVertexBuffer(    
    x0 : -1.0f
    x1 : 1.0f
    y0 : -1.0f
    y1 : 1.0f
    z0 : -1.0f
    z1 : 1.0f
    s0 : 0.0f
    s1 : 1.0f
    t0 : 0.0f
    t1 : 1.0f
) { 
    vertexBuffer!vertex_location_texture_normal(
        format : copy vertex_location_texture_normal_format
        indices : [
             0,  1,  2 // front
             0,  2,  3
             4,  5,  6 // back
             4,  6,  7
             8,  9, 10 // left
             8, 10, 11
            12, 13, 14 // right
            12, 14, 15
            16, 17, 18 // bottom
            16, 18, 19
            20, 21, 22 // top
            20, 22, 23
        ]
        vertices : [
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(0.0f, 0.0f, -1.0f)) // front
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s1, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s1, t0), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x0, y0, z1), vec2(s0, t0), vec3(0.0f, 0.0f,  1.0f)) // back
            vertex_location_texture_normal(vec3(x0, y1, z1), vec2(s0, t1), vec3(0.0f, 0.0f,  1.0f))
            vertex_location_texture_normal(vec3(x1, y1, z1), vec2(s1, t1), vec3(0.0f, 0.0f,  1.0f))
            vertex_location_texture_normal(vec3(x1, y0, z1), vec2(s1, t0), vec3(0.0f, 0.0f,  1.0f))
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(-1.0f, 0.0f, 0.0f)) // left
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t1), vec3(-1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y1, z1), vec2(s1, t1), vec3(-1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y0, z1), vec2(s1, t0), vec3(-1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s0, t0), vec3( 1.0f, 0.0f, 0.0f)) // right
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s0, t1), vec3( 1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y1, z1), vec2(s1, t1), vec3( 1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z1), vec2(s1, t0), vec3( 1.0f, 0.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(0.0f, -1.0f, 0.0f)) // bottom
            vertex_location_texture_normal(vec3(x0, y0, z1), vec2(s0, t1), vec3(0.0f, -1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z1), vec2(s1, t1), vec3(0.0f, -1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s1, t0), vec3(0.0f, -1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t0), vec3(0.0f,  1.0f, 0.0f)) // top
            vertex_location_texture_normal(vec3(x0, y1, z1), vec2(s0, t1), vec3(0.0f,  1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y1, z1), vec2(s1, t1), vec3(0.0f,  1.0f, 0.0f))
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s1, t0), vec3(0.0f,  1.0f, 0.0f))
        ]
    )
}

planeVertexBuffer(    
    x0 : -1.0f
    x1 : 1.0f
    y0 : -1.0f
    y1 : 1.0f
    z0 : 0.0f
    s0 : 0.0f
    s1 : 1.0f
    t0 : 0.0f
    t1 : 1.0f
) { 
    vertexBuffer!vertex_location_texture_normal(
        format : copy vertex_location_texture_normal_format
        indices : [
            0, 1, 2
            0, 2, 3
        ]
        vertices : [
            vertex_location_texture_normal(vec3(x0, y0, z0), vec2(s0, t0), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x0, y1, z0), vec2(s0, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y1, z0), vec2(s1, t1), vec3(0.0f, 0.0f, -1.0f))
            vertex_location_texture_normal(vec3(x1, y0, z0), vec2(s1, t0), vec3(0.0f, 0.0f, -1.0f))
        ]
    )
}

sphereVertexBuffer(
    slices : 20
    wedges : 40
    origin : vec3(0.0f, 0.0f, 0.0f)
    radius : vec3(1.0f, 1.0f, 1.0f)
) {
    vertices : array!vertex_location_texture_normal((slices + 1) * (wedges + 1))
    for slice : 0 to slices + 1 {
        tv : slice as f32 / slices as f32
        theta : f32_pi * slice as f32 / slices as f32 + f32_pi
        y0 : f32_cos(theta) * radius.y
        r0 : f32_sin(theta)
        for wedge : 0 to wedges + 1 {
            tu : wedge as f32 / wedges as f32
            angle : (2.0f * f32_pi * wedge as f32 / wedges as f32) - 1.5f * f32_pi
            x0 : f32_cos(angle) * r0 * radius.x
            z0 : f32_sin(angle) * r0 * radius.y
            normal : vec3(x0, y0, z0)

            v : vertex_location_texture_normal(
                    location : vec3(x0 + origin.x, y0 + origin.y, z0 + origin.z)
                    texture : vec2(tu, tv)
                    normal : normal.normalize())

            vertices.initAt(slice * (wedges + 1) + wedge, v)
        }
    }

    indices : array!i32(slices * wedges * 6)
    for slice : 0 to slices {
        for wedge : 0 to wedges {
            wedge0 : wedge
            wedge1 : wedge + 1

            index0 : (slice * (wedges + 1)) + wedge0
            index1 : (slice * (wedges + 1)) + wedge1
            index2 : ((slice + 1) * (wedges + 1)) + wedge1
            index3 : ((slice + 1) * (wedges + 1)) + wedge0

            indices.initAt((slice * wedges + wedge) * 6 + 0, index0)
            indices.initAt((slice * wedges + wedge) * 6 + 1, index1)
            indices.initAt((slice * wedges + wedge) * 6 + 2, index2)
            indices.initAt((slice * wedges + wedge) * 6 + 3, index2)
            indices.initAt((slice * wedges + wedge) * 6 + 4, index3)
            indices.initAt((slice * wedges + wedge) * 6 + 5, index0)
        }
    }

    vertexBuffer!vertex_location_texture_normal(
        format : copy vertex_location_texture_normal_format
        indices : copy indices
        vertices : copy vertices
    )
}