all: parser.cpp tokens.cpp

clean:
	rm parser.cpp parser.hpp tokens.cpp

parser.cpp: parser.y
	bison -v -d -l -o $@ $^
	
parser.hpp: parser.cpp

tokens.cpp: tokens.l 
	flex -L -o $@ $^
	
