package console {
    write(data : 'string)'void {
        data.nullTerminate()
        --c--
        printf("%s", (char*)data->data.data);
        --c--
    }

    writeLine(data : 'string)'void {
        data.nullTerminate()
        --c--
        printf("%s\n", (char*)data->data.data);
        --c--
    }

    readLine()'string { 
        data := nullptr
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
        data = (void*)str;
        size = index;
        --c--

        string(count := size - 1, data := array!char(dataSize := size, data := data, count := size))
    }
}