vertex_location_texture_normal_format : "vertex:3f,tex_coord:2f,normal:3f"
vertex_location_texture_normal(
    location : vec3()
    texture : vec2()
    normal : vec3()
) { this }

vertex_location_texture_normal_getRawSize() {
    vec3_getRawSize() + vec2_getRawSize() + vec3_getRawSize()
}

vertex_location_texture_normal_rawCopy(v : 'vertex_location_texture_normal, p := 'ptr) {
    p = v.location.rawCopy(p)
    p = v.texture.rawCopy(p)
    p = v.normal.rawCopy(p)
    p
}

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
        format : vertex_location_texture_normal_format
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
        format : vertex_location_texture_normal_format
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
            x0 : f32_sin(angle) * r0 * radius.x
            z0 : f32_cos(angle) * r0 * radius.y
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
        format : vertex_location_texture_normal_format
        indices : indices
        vertices : vertices
    )
}

--cfunction--
#include(<lib/ui/obj_parser.h>)
##include <lib/ui/obj_parser.c>
--cfunction--

vertexBuffer_loadObj(filename : 'string) {
    indices : list!i32()
    vertices : list!vertex_location_texture_normal()
    location := vec3()
    texture := vec2()
    normal := vec3()
    index := 0
    includeNormals := true
    includeTextures := true
    --c--
    obj_scene_data data = { 0 };
    if (parse_obj_scene(&data, (char*)filename->data.data)) {
        for (int i = 0; i < data.face_count; i++) {
            if (data.face_list[i]->vertex_count != 3) {
                printf("warn: do not support obj with non-triangles\n");
            }

            for (int j = 0; j < 3; j++) {
                sjv_index = data.face_list[i]->vertex_index[j];
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->normal_index[j]) {
                    sjv_includenormals = false;
                }
                if (data.face_list[i]->vertex_index[j] != data.face_list[i]->texture_index[j]) {
                    sjv_includetextures = false;
                }
    --c--
                indices.add(index)
    --c--
            }
        }

        if (data.vertex_count != data.vertex_normal_count) {
            sjv_includenormals = false;
        }

        if (data.vertex_count != data.vertex_texture_count) {
            sjv_includetextures = false;
        }

        for (int i = 0; i < data.vertex_count; i++) {
            sjv_location.x = (float)data.vertex_list[i]->e[0];
            sjv_location.y = (float)data.vertex_list[i]->e[1];
            sjv_location.z = (float)data.vertex_list[i]->e[2];

            if (sjv_includenormals) {
                sjv_normal.x = (float)data.vertex_normal_list[i]->e[0];
                sjv_normal.y = (float)data.vertex_normal_list[i]->e[1];
                sjv_normal.z = (float)data.vertex_normal_list[i]->e[2];            
            }

            if (sjv_includetextures) {
                sjv_texture.x = (float)data.vertex_texture_list[i]->e[0];
                sjv_texture.y = (float)data.vertex_texture_list[i]->e[1];
            }

    --c--
            debug.writeLine(location.asString() + " " + normal.asString() + " " + texture.asString())
            vertices.add(vertex_location_texture_normal(
                location : location
                texture : texture
                normal : normal
            ))
    --c--
        }

    }
    delete_obj_data(&data);
    --c--

    // If file does not provide normals then compute them
    if !includeNormals {
        normals : array!vec3(vertices.count)
        for i : 0 to vertices.count {
            normals.initAt(i, vec3())
        }

        for i : 0 to indices.count / 3 {
            i1 : indices[i * 3 + 0]
            i2 : indices[i * 3 + 1]
            i3 : indices[i * 3 + 2]

            v1 : vertices[i1].location
            v2 : vertices[i2].location
            v3 : vertices[i3].location

            side1 : v2 - v1
            side2 : v3 - v1

            newNormal : side2.cross(side1).normalize()

            normals[i1] = normals[i1] + newNormal
            normals[i2] = normals[i2] + newNormal
            normals[i3] = normals[i3] + newNormal
        }

        for i : 0 to vertices.count {
            newNormal : normals[i].normalize()
            vertices[i] = vertex_location_texture_normal(
                location : vertices[i].location
                texture : vertices[i].texture
                normal : newNormal
            )
        }
    }

    // If file does not provide textures then compute them
    if !includeTextures {
        yMin := 0.0f
        yMax := 0.0f
        for i : 0 to vertices.count {
            yMin = yMin.min(vertices[i].location.y)
            yMax = yMax.max(vertices[i].location.y)
        }

        for i : 0 to vertices.count {
            s : (f32_atan2(vertices[i].location.x, vertices[i].location.z) + f32_pi) / (2.0f * f32_pi)
            t : (vertices[i].location.y - yMin) / (yMax - yMin)
            vertices[i] = vertex_location_texture_normal(
                location : vertices[i].location
                texture : vec2(s, t)
                normal : vertices[i].normal
            )
        }
    }

    vertexBuffer!vertex_location_texture_normal(
        format : vertex_location_texture_normal_format
        indices : indices.array
        vertices : vertices.array
    )
}