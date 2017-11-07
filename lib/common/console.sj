console : ^(
	_fd = 0 as ptr

	write(data : 'string)'void c{
		fwrite(data->data, sizeof(char), data->size, (FILE*)_parent->_fd);
	}c

	readLine()'string { 
		data = 0 as ptr
		size = 0
		c{
		    auto str = (char*)malloc(size);
		    auto index = 0;
		    auto ch = ' ';
		    do {
		        ch = getchar();
		        if (ch != '\n') {
		            str[index] = ch;
		            index++;
		            if (index > size) {
		                size *= 2;
		                str = (char*)realloc(str, size);
		            }
		        }
		    } while (ch != '\n');

		    data = str;
		    size = index;
		}c

		string(count = size, data = array!char(size = size, data = data))
	}
) { 
	c{ 
		_this->_fd = (uintptr_t)fopen(stdout, "w");
	}c
	this
}