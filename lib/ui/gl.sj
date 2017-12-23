enum glFeature (
	GL_BLEND : 0x0BE2
    GL_CULL_FACE : 0x0B44
    GL_DEPTH_TEST : 0x0B71
    GL_DITHER : 0x0BD0
    GL_POLYGON_OFFSET_FILL : 0x8037
    GL_SAMPLE_ALPHA_TO_COVERAGE : 0x809E
    GL_SAMPLE_COVERAGE : 0x80A0
    GL_SCISSOR_TEST : 0x0C11
    GL_STENCIL_TEST : 0x0B90
)

enum glTexture (
	GL_TEXTURE_2D : 0x0DE1
	GL_TEXTURE_CUBE_MAP : 0x8513
)

enum glTextureAttribute (
	GL_TEXTURE_MIN_FILTER : 0x2801
	GL_TEXTURE_MAG_FILTER : 0x2800
	GL_TEXTURE_WRAP_S : 0x2802
	GL_TEXTURE_WRAP_T : 0x2803
)

enum glTextureValue (
	GL_CLAMP_TO_EDGE : 0x812F
	GL_MIRRORED_REPEAT : 0x8370
	GL_REPEAT : 0x2901
	GL_NEAREST : 0x2600
	GL_LINEAR : 0x2601
	GL_NEAREST_MIPMAP_NEAREST : 0x2700
	GL_LINEAR_MIPMAP_NEAREST : 0x2701
	GL_NEAREST_MIPMAP_LINEAR : 0x2702
	GL_LINEAR_MIPMAP_LINEAR : 0x2703
)

enum glTextureFormat (
	GL_ALPHA : 0x1906
	GL_LUMINANCE : 0x1909
	GL_LUMINANCE_ALPHA : 0x190A
	GL_RGB : 0x1907
	GL_RGBA : 0x1908
)

enum glTextureType (
	GL_UNSIGNED_BYTE : 0x1401
	GL_UNSIGNED_SHORT_5_6_5 : 0x8363
	GL_UNSIGNED_SHORT_4_4_4_4 : 0x8033
	GL_UNSIGNED_SHORT_5_5_5_1 : 0x8034
)

enum glFramebufferAttachment(
	GL_COLOR_ATTACHMENT0 : 0x8CE0
	GL_DEPTH_ATTACHMENT : 0x8D00
	GL_STENCIL_ATTACHMENT : 0x8D20
)

enum glFramebufferTexture(
	GL_TEXTURE_2D : 0x0DE1
	GL_TEXTURE_CUBE_MAP_POSITIVE_X : 0x8515
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X : 0x8516
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y : 0x8517
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y : 0x8518
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z : 0x8519
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z : 0x851A
)

enum glRenderbufferFormat(
	GL_RGBA4 : 0x8056
	GL_RGB565 : 0x8D62
	GL_RGB5_A1 : 0x8057
	GL_DEPTH_COMPONENT16 : 0x81A5
	GL_STENCIL_INDEX8 : 0x8D48
)

enum glFramebufferStatus(
	GL_FRAMEBUFFER_COMPLETE : 0x8CD5
	GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT : 0x8CD6
	GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT : 0x8CD7
	GL_FRAMEBUFFER_UNSUPPORTED : 0x8CDD
)

enum glBlendFuncType(
	GL_ZERO : 0
	GL_ONE : 1
	GL_SRC_COLOR : 0x0300
	GL_ONE_MINUS_SRC_COLOR : 0x0301
	GL_DST_COLOR : 0x0306
	GL_ONE_MINUS_DST_COLOR : 0x0307
	GL_SRC_ALPHA : 0x0302
	GL_ONE_MINUS_SRC_ALPHA : 0x0303
	GL_DST_ALPHA : 0x0304
	GL_ONE_MINUS_DST_ALPHA : 0x0305
	GL_CONSTANT_COLOR : 0x8001
	GL_ONE_MINUS_CONSTANT_COLOR : 0x8002
	GL_CONSTANT_ALPHA : 0x8003
	GL_ONE_MINUS_CONSTANT_ALPHA : 0x8004
	GL_SRC_ALPHA_SATURATE : 0x0308
)

glEnable(feature : 'glFeature) {
	--c--
	glEnable(feature);
	--c--
}

glDisable(feature : 'glFeature) {
	--c--
	glDisable(feature);
	--c--
}

glViewports : list!rect()

glPushViewport(rect : 'rect, sceneRect : 'rect) {
	newRect : rect(rect.x, sceneRect.h - (rect.y + rect.h), rect.w, rect.h)
	glViewports.add(newRect)
	--c--
	glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);
	--c--
}

glPopViewport(rect : 'rect, sceneRect : 'rect) {
	oldRect : rect(rect.x, sceneRect.h - (rect.y + rect.h), rect.w, rect.h)
	if glViewports[glViewports.count - 1] != oldRect {
		halt("viewport being pop'ed is wrong")
	}
	glViewports.removeAt(glViewports.count - 1)
	newRect : if glViewports.count > 0 { glViewports[glViewports.count - 1] } else { rect() }
	--c--
	glViewport(sjv_newrect.x, sjv_newrect.y, sjv_newrect.w, sjv_newrect.h);
	--c--
}

glFrameBuffers : list!u32()

glPushFramebuffer(framebuffer : 'framebuffer) {
	glFrameBuffers.add(framebuffer.id)
	--c--
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
    --c--
}

glPopFramebuffer(framebuffer : 'framebuffer) {
	if glFrameBuffers[glFrameBuffers.count - 1] != frameBuffer.id {
		halt("framebuffer being pop'ed is wrong")
	}
	glFrameBuffers.removeAt(glFrameBuffers.count - 1)
	id : if glFrameBuffers.count > 0 { glFrameBuffers[glFrameBuffers.count - 1] } else { 0u }
	--c--
	glBindFramebuffer(GL_FRAMEBUFFER, sjv_id);
	--c--
}

glUseProgram(shader : 'shader) {
	--c--
    glUseProgram(shader->id);
	--c--
}

glBindTexture(type : 'glTexture, texture : 'texture) {
	--c--
    glBindTexture(type, texture->id);
	--c--
}

glGetUniformLocation(shader : 'shader, name : 'string) {
	--c--
	int result = glGetUniformLocation(shader->id, (char*)name->data.data);
	#return(i32, result);
	--c--
}

glUniformMat4(loc : 'i32, m : 'mat4) {
	--c--
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)&m->m00);
	--c--	
}

glUniformVec3(loc : 'i32, v : 'vec3) {
	--c--
    glUniform3fv(loc, 1, (GLfloat*)&v->x);
	--c--	
}

glUniformI32(loc : 'i32, v : 'i32) {
	--c--
    glUniform1i(loc, v);
	--c--	
}

glUniformF32(loc : 'i32, v : 'f32) {
	--c--
    glUniform1f(loc, v);
	--c--	
}

glGenFramebuffer(size : 'size)'framebuffer {
	id := 0u
	--c--
	glGenFramebuffers(1, &sjv_id);
	--c--
	framebuffer(copy size, id)
}

glGenTexture(size: 'size)'texture {
	id := 0u
	--c--
    glGenTextures(1, &sjv_id);
    --c--
    texture(copy size, id)
}

glTexParameteri(type : 'glTexture, attribute : 'glTextureAttribute, val : 'glTextureValue) {
	--c--
    glTexParameteri(type, attribute, val);
    --c--
}

glTexImage2D(type : 'glTexture, level : 'i32, format : 'glTextureFormat, size : 'size, dataType : 'glTextureType, data : nullptr) {
	--c--
    glTexImage2D(type, level, format, size->w, size->h, 0, format, datatype, data);
    --c--
}

glFramebufferTexture2D(attachment : 'glFramebufferAttachment, target : 'glFramebufferTexture, texture : 'texture, level : 'i32) {
	--c--
    glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, texture->id, level);
    --c--
}

glGenRenderbuffer(size: 'size) {
	id := 0u
	--c--
    glGenRenderbuffers(1, &sjv_id); 
    --c--
    renderbuffer(copy size, id)
}

glRenderbufferStorage(format : 'glRenderbufferFormat, size : 'size) {
	--c--
    glRenderbufferStorage(GL_RENDERBUFFER, format, size->w, size->h);
    --c--
}

glFramebufferRenderbuffer(attachment : 'glFramebufferAttachment, renderbuffer : 'renderbuffer) {
	--c--
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, renderbuffer->id);
    --c--
}

glCheckFramebufferStatus()'glFramebufferStatus {
	status := glFramebufferStatus.GL_FRAMEBUFFER_UNSUPPORTED
	--c--
    sjv_status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    --c--
    status
}

glBindRenderbuffer(renderbuffer : 'renderbuffer) {
	--c--
	glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer->id);
	--c--
}


glClearColor(color : 'color) {
	--c--
	glClearColor(color->r, color->g, color->b, color->a);
	--c--
}

glBlendFunc(sfactor : 'glBlendFuncType, dfactor : 'glBlendFuncType) {
	--c--
	glBlendFunc(sfactor, dfactor);
	--c--
}

--cdefine--
void glid_retain(GLuint id);
bool glid_release(GLuint id);
void glid_gethash(GLuint id, uint32_t* result);
void glid_isequal(GLuint id1, GLuint id2, bool* result);
--cdefine--

--cfunction--
KHASH_INIT_TYPEDEF(glid_hash_type, GLuint, int)
KHASH_INIT_FUNCTION(glid_hash_type, GLuint, int, 1, glid_gethash, glid_isequal)
khash_t(glid_hash_type)* glid_hash;

void glid_gethash(GLuint id, uint32_t* result) {
    *result = kh_int_hash_func(id);
}

void glid_isequal(GLuint id1, GLuint id2, bool* result) {
    *result = (id2 == id2);
}

void glid_init() {
    glid_hash = kh_init(glid_hash_type);
}

void glid_retain(GLuint id) {
    khiter_t k = kh_get(glid_hash_type, glid_hash, id);
    if (k == kh_end(glid_hash)) {
        int ret;
        khiter_t k = kh_put(glid_hash_type, glid_hash, id, &ret);
        if (!ret) kh_del(glid_hash_type, glid_hash, k);
        kh_value(glid_hash, k) = 1;
    }
    else {
        kh_value(glid_hash, k)++;
    }
}

bool glid_release(GLuint id) {
    khiter_t k = kh_get(glid_hash_type, glid_hash, id);
    if (k != kh_end(glid_hash)) {
        kh_value(glid_hash, k)--;
        if (kh_value(glid_hash, k) == 0) {
            kh_del(glid_hash_type, glid_hash, k);
        }
        return false;
    }
    return true;
}
--cfunction--

--c--
glid_init();
--c--