parse: ^(
	toInt(text : 'string)'i32 {
		x = 0
		c{
			char* e;
		    int v = (int)strtol((char*)text->data.data, &e, 10);
		    
		    if (*e != '\0') {
		        x = 0;
		    }
		    else {
		    	x = v;
			}
	    }c
	    x
    }
) { this }