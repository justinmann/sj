all: parser.cpp tokens.cpp

clean:
	rm parser.cpp parser.hpp tokens.cpp

parser.cpp: parser.y
	/usr/local/opt/bison/bin/bison -v -d -l -o $@ $^
	
parser.hpp: parser.cpp

tokens.cpp: tokens.l 
	/usr/local/opt/flex/bin/flex -L -o $@ $^
	
