console : ^(
	write(data : 'string)'void {
		--c--
		#include(<stdio.h>)
		printf("%s\n", (char*)data->data.data);
		--c--
	}

	readLine()'string { 
		data := 0 as ptr
		size := 1024
		--c--
		#include(<stdio.h>)
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
		--c--

		string(count := size - 1, data := array!char(size := size, data := data))
	}
) { this }