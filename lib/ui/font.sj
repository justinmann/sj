font(
	src : 'string
	size : 'i32
	data = 0 as ptr
) {
/*	c{
	    _this->data = (uintptr_t)TTF_OpenFont((char*)_this->src.data.data, _this->size);
	    if (_this->data == 0) {
	        printf("TTF_OpenFont Error\n");
	    }	
	}c
*/
	this
} destroy c{
//	TTF_CloseFont((TTF_Font*)_this->data);	
}c