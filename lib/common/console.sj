console : ^(
	_fd = 0 as ptr

	write(data : 'string)'void {
		c{
			#forceParent()
				
			fwrite((void*)data->data->data, sizeof(char), data->count, (FILE*)_parent->_fd);
		}c
	}

	readLine()'string { 
		data = 0 as ptr
		size = 1024
		c{
		    char* str = (char*)malloc(size);
		    int index = 0;
		    char ch = ' ';
		    do {
		        ch = getchar();
		        if (ch != '\n') {
		            str[index] = ch;
		            index++;
		            if (index >= size) {
		                size *= 2;
		                str = (char*)realloc(str, size);
		            }
		        }
		    } while (ch != '\n');

			str[index] = 0;
		    index++;
		    data = (uintptr_t)str;
		    size = index;
		}c

		string(count = size - 1, data = array!char(size = size, data = data))
	}
) { 
	c{ 
		#include(<stdio.h>)
		_this->_fd = (uintptr_t)stdout;
	}c
	this
}