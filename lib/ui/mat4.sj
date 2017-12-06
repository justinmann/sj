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
            m00 : m00 * x.m00 + m01 * m10 + m02 * m20 + m03 * m30
            m01 : m00 * x.m01 + m01 * m11 + m02 * m21 + m03 * m31
            m02 : m00 * x.m02 + m01 * m12 + m02 * m22 + m03 * m32
            m03 : m00 * x.m03 + m01 * m13 + m02 * m23 + m03 * m33
            m10 : m10 * x.m00 + m11 * m10 + m12 * m20 + m13 * m30
            m11 : m10 * x.m01 + m11 * m11 + m12 * m21 + m13 * m31
            m12 : m10 * x.m02 + m11 * m12 + m12 * m22 + m13 * m32
            m13 : m10 * x.m03 + m11 * m13 + m12 * m23 + m13 * m33
            m20 : m20 * x.m00 + m21 * m10 + m22 * m20 + m23 * m30
            m21 : m20 * x.m01 + m21 * m11 + m22 * m21 + m23 * m31
            m22 : m20 * x.m02 + m21 * m12 + m22 * m22 + m23 * m32
            m23 : m20 * x.m03 + m21 * m13 + m22 * m23 + m23 * m33
            m30 : m30 * x.m00 + m31 * m10 + m32 * m20 + m33 * m30
            m31 : m30 * x.m01 + m31 * m11 + m32 * m21 + m33 * m31
            m32 : m30 * x.m02 + m31 * m12 + m32 * m22 + m33 * m32
            m33 : m30 * x.m03 + m31 * m13 + m32 * m23 + m33 * m33
        )
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

mat4_rotation(angle : 'f32, x : 'f32, y : 'f32, z : 'f32) {
    c : f32_cos(f32_pi * angle / 180.0f)
    s : f32_sin(f32_pi * angle / 180.0f)
    norm : f32_sqrt(x * x + y * y + z * z)

    xnorm = x / norm
    ynorm = y / norm
    znorm = z / norm;

    mat4(
        m00 : xnorm * xnorm * (1.0f - c) + c
        m10 : ynorm * xnorm * (1.0f - c) - znorm * s
        m20 : znorm * xnorm * (1.0f - c) + ynorm * s
        m01 : xnorm * ynorm * (1.0f - c) + znorm * s
        m11 : ynorm * ynorm * (1.0f - c) + c
        m21 : znorm * ynorm * (1.0f - c) - xnorm * s
        m02 : xnorm * znorm * (1.0f - c) - ynorm * s
        m12 : ynorm * znorm * (1.0f - c) + xnorm * s
        m22 : znorm * znorm * (1.0f - c) + c
        m33 : 1.0f
    )
}

mat4_translate(x : 'f32, y : 'f32, z : 'f32) {
    mat4(
        m00 : 1.0f
        m11 : 1.0f
        m22 : 1.0f
        m30 : x
        m31 : y
        m32 : z
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
