parse: ^(
	toInt(text : 'string)'i32 c{
		char* e;
	    int v = strtol((char*)text->data->data, &e, 10);
	    
	    if (*e != '\0') {
	        return 0;
	    }
	    
	    return v;
    }c
) { this }