image(
	texture : texture()
	rect = rect()
	margin : margin()
) { 
	if rect.w == 0 && rect.h == 0 {
		size : texture.getSize()
		rect = copy rect(0, 0, size.w, size.h)
		void
	}
	this 
}