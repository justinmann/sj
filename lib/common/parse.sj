parse: ^(
	toInt(text : 'string)'i32 c{
		char* e;
	    int v = strtol((char*)text->data->data, &e, 10);
	    
	    if (*e != '\0') {
	        *_return = 0;
	    }
	    
	    *_return = v;
    }c
) { this }