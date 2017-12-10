frameBuffer(
	size : 'size
	--cvar--
	GLuint frameBufferId;
	GLuint textureId;
	GLuint depthBufferId
	--cvar--
) {
	--c--
	glGenFramebuffers(1, &_this->frameBufferId);
    glGenTextures(1, &_this->textureId);
    glBindFramebuffer(GL_FRAMEBUFFER, _this->frameBufferId);

    glBindTexture(GL_TEXTURE_2D, _this->textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _this->size.w, _this->size.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _this->textureId, 0);

    glGenRenderbuffers(1, &_this->depthBufferId);    
    glBindRenderbuffer(GL_RENDERBUFFER, _this->depthBufferId);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, _this->size.w, _this->size.h);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _this->depthBufferId);

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if(status != GL_FRAMEBUFFER_COMPLETE) {
        printf("Framebuffer status: %x", (int)status);       
    }
	--c--
	this 
} copy {
    --c--
    _this->frameBufferId = _from->frameBufferId;
    _retainGLid(_this->frameBufferId);
    _this->textureId = _from->textureId;
    _retainGLid(_this->textureId);
    _this->depthBufferId = _from->depthBufferId;
    _retainGLid(_this->depthBufferId);
    --c--
} destroy {
    --c--
    if (_releaseGLid(_this->frameBufferId)) {
        glDeleteFramebuffers(1, &_this->frameBufferId);
    }
    if (_releaseGLid(_this->textureId)) {
        glDeleteTextures(1, &_this->textureId);
    }
    if (_releaseGLid(_this->depthBufferId)) {
        glDeleteRenderbuffers(1, &_this->depthBufferId);
    }
    --c--
}