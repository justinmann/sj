scenebuffer(
	size : size()
	framebuffer := framebuffer()
    texture := texture()
    renderbuffer := renderbuffer()
) {
    framebuffer = glGenFramebuffer(size)
    texture = glGenTexture(size)
    renderbuffer = glGenRenderbuffer(size)

    glPushFramebuffer(framebuffer)
    glBindTexture(glTexture.GL_TEXTURE_2D, texture)
    glTexParameteri(glTexture.GL_TEXTURE_2D, glTextureAttribute.GL_TEXTURE_WRAP_S, glTextureValue.GL_CLAMP_TO_EDGE)
    glTexParameteri(glTexture.GL_TEXTURE_2D, glTextureAttribute.GL_TEXTURE_WRAP_T, glTextureValue.GL_CLAMP_TO_EDGE)
    glTexParameteri(glTexture.GL_TEXTURE_2D, glTextureAttribute.GL_TEXTURE_MIN_FILTER, glTextureValue.GL_LINEAR)
    glTexParameteri(glTexture.GL_TEXTURE_2D, glTextureAttribute.GL_TEXTURE_MAG_FILTER, glTextureValue.GL_LINEAR)
    glTexImage2D(glTexture.GL_TEXTURE_2D, 0, glTextureFormat.GL_RGBA, size, glTextureType.GL_UNSIGNED_BYTE)
    glFramebufferTexture2D(glFramebufferAttachment.GL_COLOR_ATTACHMENT0, glFramebufferTexture.GL_TEXTURE_2D, texture, 0)

    glBindRenderbuffer(renderbuffer)
    glRenderbufferStorage(glRenderbufferFormat.GL_DEPTH_COMPONENT16, size)
    glFramebufferRenderbuffer(glFramebufferAttachment.GL_DEPTH_ATTACHMENT, renderbuffer)

    status : glCheckFramebufferStatus()
    if status != glFramebufferStatus.GL_FRAMEBUFFER_COMPLETE {
        halt("Framebuffer failed")       
    }
    glPopFramebuffer(framebuffer)

	this
}