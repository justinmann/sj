parse: ^(
	toInt(text : 'string)'i32 c{
		char* e;
	    errno = 0;
	    auto v = strtol(text->data->data, &e, 10);
	    
	    if (ERANGE == errno) {
	        return 0;
	    }
	    
	    if (*e != '\0') {
	        return 0;
	    }
	    
	    return v;
    }c
) { this }