--cinclude--
#include(<stdio.h>)
--cinclude--

console : ^(
	write(data : 'string)'void {
		--c--
		printf("%s", (char*)data->data.data);
		--c--
	}

	writeLine(data : 'string)'void {
		--c--
		printf("%s\n", (char*)data->data.data);
		--c--
	}

	readLine()'string { 
		data := 0 as ptr
		size := 1024
		--c--
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

		string(count := size - 1, data := array!char(dataSize := size, data := data, count := size))
	}
) { this }