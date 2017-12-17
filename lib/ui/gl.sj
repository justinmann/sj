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

glViewport(rect : 'rect) {
	--c--
	glViewport(rect->x, rect->y, rect->w, rect->h);
	--c--
}

glBindFramebuffer(framebuffer : 'framebuffer) {
	--c--
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->id);
    --c--
}

glUnbindFramebuffer() {
	--c--
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
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
    glUniformMatrix4fv(loc, 1, 0, (GLfloat*)m);
	--c--	
}

glUniformVec3(loc : 'i32, v : 'vec3) {
	--c--
    glUniform3fv(loc, 1, (GLfloat*)v);
	--c--	
}

glGenFramebuffer()'framebuffer {
	id := 0u
	--c--
	glGenFramebuffers(1, &sjv_id);
	--c--
	framebuffer(id)
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

--cstruct--
typedef struct GLid_td GLid_s;

struct GLid_td {
    GLuint id;
    int refCount;
    UT_hash_handle hh;
};

GLid_s* g_GLids = 0;
--cstruct--

--cdefine--
void _retainGLid(GLuint id);
bool _releaseGLid(GLuint id);
--cdefine--

--cfunction--
void _retainGLid(GLuint id) {
  GLid_s* p;
  HASH_FIND_PTR(g_GLids, &id, p);
  if (p) {
    p->refCount++;
  } else {
    p = (GLid_s*)malloc(sizeof(GLid_s));
    p->id = id;
    p->refCount = 1;
    HASH_ADD_PTR(g_GLids, id, p);    
  }
}

bool _releaseGLid(GLuint id) {
  GLid_s* p;
  HASH_FIND_PTR(g_GLids, &id, p);
  if (p) {
    p->refCount--;
    if (p->refCount == 0) {
      HASH_DEL(g_GLids, p);
      free(p);
    }
    return false;
  }
  return true;
}
--cfunction--