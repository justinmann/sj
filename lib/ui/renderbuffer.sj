renderbuffer(
    size : size()
    id : 0u
) { 
    this 
} copy {
    --c--
    _this->id = _from->id;
    _retainGLid(_this->id);
    --c--
} destroy {
    --c--
    if (_releaseGLid(_this->id)) {
        glDeleteRenderbuffers(1, &_this->id);
    }
    --c--
}