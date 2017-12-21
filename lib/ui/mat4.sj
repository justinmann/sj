mat4(
    m00 : 0.0f
    m01 : 0.0f
    m02 : 0.0f
    m03 : 0.0f
    m10 : 0.0f
    m11 : 0.0f
    m12 : 0.0f
    m13 : 0.0f
    m20 : 0.0f
    m21 : 0.0f
    m22 : 0.0f
    m23 : 0.0f
    m30 : 0.0f
    m31 : 0.0f
    m32 : 0.0f
    m33 : 0.0f

    multiply(m : 'mat4) {
        mat4(
            m00 : m.m00 * m00 + m.m01 * m10 + m.m02 * m20 + m.m03 * m30
            m01 : m.m00 * m01 + m.m01 * m11 + m.m02 * m21 + m.m03 * m31
            m02 : m.m00 * m02 + m.m01 * m12 + m.m02 * m22 + m.m03 * m32
            m03 : m.m00 * m03 + m.m01 * m13 + m.m02 * m23 + m.m03 * m33
            m10 : m.m10 * m00 + m.m11 * m10 + m.m12 * m20 + m.m13 * m30
            m11 : m.m10 * m01 + m.m11 * m11 + m.m12 * m21 + m.m13 * m31
            m12 : m.m10 * m02 + m.m11 * m12 + m.m12 * m22 + m.m13 * m32
            m13 : m.m10 * m03 + m.m11 * m13 + m.m12 * m23 + m.m13 * m33
            m20 : m.m20 * m00 + m.m21 * m10 + m.m22 * m20 + m.m23 * m30
            m21 : m.m20 * m01 + m.m21 * m11 + m.m22 * m21 + m.m23 * m31
            m22 : m.m20 * m02 + m.m21 * m12 + m.m22 * m22 + m.m23 * m32
            m23 : m.m20 * m03 + m.m21 * m13 + m.m22 * m23 + m.m23 * m33
            m30 : m.m30 * m00 + m.m31 * m10 + m.m32 * m20 + m.m33 * m30
            m31 : m.m30 * m01 + m.m31 * m11 + m.m32 * m21 + m.m33 * m31
            m32 : m.m30 * m02 + m.m31 * m12 + m.m32 * m22 + m.m33 * m32
            m33 : m.m30 * m03 + m.m31 * m13 + m.m32 * m23 + m.m33 * m33
        )
    }

    multiplyF32(x : 'f32) {
        mat4(
            m00 * x
            m01 * x
            m02 * x
            m03 * x
            m10 * x
            m11 * x
            m12 * x
            m13 * x
            m20 * x
            m21 * x
            m22 * x
            m23 * x
            m30 * x
            m31 * x
            m32 * x
            m33 * x
        )
    }


    multiplyVec4(v : 'vec4) {
        vec4(
            m00 * v.x + m10 * v.y + m20 * v.z + m30 * v.w
            m01 * v.x + m11 * v.y + m21 * v.z + m31 * v.w
            m02 * v.x + m12 * v.y + m22 * v.z + m32 * v.w
            m03 * v.x + m13 * v.y + m23 * v.z + m33 * v.w
        )
    }

    invert() {
        t : mat4(
           m00 : m12*m23*m31 - m13*m22*m31 + m13*m21*m32 - m11*m23*m32 - m12*m21*m33 + m11*m22*m33
           m01 : m03*m22*m31 - m02*m23*m31 - m03*m21*m32 + m01*m23*m32 + m02*m21*m33 - m01*m22*m33
           m02 : m02*m13*m31 - m03*m12*m31 + m03*m11*m32 - m01*m13*m32 - m02*m11*m33 + m01*m12*m33
           m03 : m03*m12*m21 - m02*m13*m21 - m03*m11*m22 + m01*m13*m22 + m02*m11*m23 - m01*m12*m23
           m10 : m13*m22*m30 - m12*m23*m30 - m13*m20*m32 + m10*m23*m32 + m12*m20*m33 - m10*m22*m33
           m11 : m02*m23*m30 - m03*m22*m30 + m03*m20*m32 - m00*m23*m32 - m02*m20*m33 + m00*m22*m33
           m12 : m03*m12*m30 - m02*m13*m30 - m03*m10*m32 + m00*m13*m32 + m02*m10*m33 - m00*m12*m33
           m13 : m02*m13*m20 - m03*m12*m20 + m03*m10*m22 - m00*m13*m22 - m02*m10*m23 + m00*m12*m23
           m20 : m11*m23*m30 - m13*m21*m30 + m13*m20*m31 - m10*m23*m31 - m11*m20*m33 + m10*m21*m33
           m21 : m03*m21*m30 - m01*m23*m30 - m03*m20*m31 + m00*m23*m31 + m01*m20*m33 - m00*m21*m33
           m22 : m01*m13*m30 - m03*m11*m30 + m03*m10*m31 - m00*m13*m31 - m01*m10*m33 + m00*m11*m33
           m23 : m03*m11*m20 - m01*m13*m20 - m03*m10*m21 + m00*m13*m21 + m01*m10*m23 - m00*m11*m23
           m30 : m12*m21*m30 - m11*m22*m30 - m12*m20*m31 + m10*m22*m31 + m11*m20*m32 - m10*m21*m32
           m31 : m01*m22*m30 - m02*m21*m30 + m02*m20*m31 - m00*m22*m31 - m01*m20*m32 + m00*m21*m32
           m32 : m02*m11*m30 - m01*m12*m30 - m02*m10*m31 + m00*m12*m31 + m01*m10*m32 - m00*m11*m32
           m33 : m01*m12*m20 - m02*m11*m20 + m02*m10*m21 - m00*m12*m21 - m01*m10*m22 + m00*m11*m22
       )

       t * (1.0f / determinant())
    }

    determinant() {
       m03*m12*m21*m30 - m02*m13*m21*m30 - m03*m11*m22*m30 + m01*m13*m22*m30 + m02*m11*m23*m30 - m01*m12*m23*m30 - m03*m12*m20*m31 + m02*m13*m20*m31 + m03*m10*m22*m31 - m00*m13*m22*m31 - m02*m10*m23*m31 + m00*m12*m23*m31 + m03*m11*m20*m32 - m01*m13*m20*m32 - m03*m10*m21*m32 + m00*m13*m21*m32 + m01*m10*m23*m32 - m00*m11*m23*m32 - m02*m11*m20*m33 + m01*m12*m20*m33 + m02*m10*m21*m33 - m00*m12*m21*m33 - m01*m10*m22*m33 + m00*m11*m22*m33
    }

    transpose() {
        mat4(
            m00 : m00
            m01 : m10
            m02 : m20
            m03 : m30
            m10 : m01
            m11 : m11
            m12 : m21
            m13 : m31
            m20 : m02
            m21 : m12
            m22 : m22
            m23 : m32
            m30 : m03
            m31 : m13
            m32 : m23
            m33 : m33
        )
    }

    asString() {
        "[[" + m00.asString() + " " + m01.asString() + " " + m02.asString() + " " + m03.asString() + "] [" + m10.asString() + " " + m11.asString() + " " + m12.asString() + " " + m13.asString() + "] [" + m20.asString() + " " + m21.asString() + " " + m22.asString() + " " + m23.asString() + "] [" + m30.asString() + " " + m31.asString() + " " + m32.asString() + " " + m33.asString() + "]"
    }
) { this }

mat4_identity() {
    mat4(
        m00 : 1.0f
        m11 : 1.0f
        m22 : 1.0f
        m33 : 1.0f
    )
}

mat4_lookAtLH(camera : 'vec3, target : 'vec3, up : 'vec3) {
    temp : target - camera
    zaxis : temp.normalize()
    xaxis : up.cross(zaxis).normalize()
    yaxis : zaxis.cross(xaxis)
    mat4(
        xaxis.x
        yaxis.x
        zaxis.x
        0.0f
        xaxis.y
        yaxis.y
        zaxis.y
        0.0f
        xaxis.z
        yaxis.z
        zaxis.z
        0.0f
        0.0f - xaxis.dot(camera)
        0.0f - yaxis.dot(camera)
        0.0f - zaxis.dot(camera)
        1.0f
    )
}

mat4_perspective(fovy : 'f32, aspect : 'f32, znear : 'f32, zfar : 'f32) {
    yscale : 1.0f / f32_tan(fovy / 180.0f / 2.0f)
    xscale : yscale * aspect
    mat4(
        m00 : xscale
        m11 : yscale
        m22 : zfar / (zfar - znear)
        m23 : 1.0f
        m32 : 0.0f - znear * zfar / (zfar-znear)
    )
}

mat4_orthographic(left : 'f32, right : 'f32, bottom : 'f32, top : 'f32, znear : 'f32, zfar : 'f32) {
    mat4(
        m00 : 2.0f / (right - left)
        m30 : 0.0f - (right + left) / (right - left)
        m11 : 2.0f / (top - bottom)
        m31 : 0.0f - (top + bottom) / (top - bottom)
        m22 : -2.0f / (zfar - znear)
        m32 : 0.0f - (zfar + znear) / (zfar-znear)
        m33 : 1.0f
    )
}

mat4_rotate(angle : 'f32, axis : 'vec3) {
    c : f32_cos(f32_pi * angle / 180.0f)
    s : f32_sin(f32_pi * angle / 180.0f)
    norm : axis.normalize()

    mat4(
        m00 : norm.x * norm.x * (1.0f - c) + c
        m10 : norm.y * norm.x * (1.0f - c) - norm.z * s
        m20 : norm.z * norm.x * (1.0f - c) + norm.y * s
        m01 : norm.x * norm.y * (1.0f - c) + norm.z * s
        m11 : norm.y * norm.y * (1.0f - c) + c
        m21 : norm.z * norm.y * (1.0f - c) - norm.x * s
        m02 : norm.x * norm.z * (1.0f - c) - norm.y * s
        m12 : norm.y * norm.z * (1.0f - c) + norm.x * s
        m22 : norm.z * norm.z * (1.0f - c) + c
        m33 : 1.0f
    )
}

mat4_translate(offset : 'vec3) {
    mat4(
        m00 : 1.0f
        m11 : 1.0f
        m22 : 1.0f
        m30 : offset.x
        m31 : offset.y
        m32 : offset.z
        m33 : 1.0f
    )
}

mat4_scale(x : 'f32, y : 'f32, z : 'f32) {
    mat4(
        m00 : x
        m11 : y
        m22 : z
        m33 : 1.0f
    )
}
