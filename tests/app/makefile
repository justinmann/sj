TARGET = all
LIBS = -lm
CC = emcc
CFLAGS = -g -Wall -s CYBERDWARF=1 -s SAFE_HEAP=1
SJ_OBJECTS = $(patsubst %.sj, %.c, $(wildcard *.sj))

.PHONY: default all clean
.PRECIOUS: $(SJ_OBJECTS)

all: default

default: timer highlow

clean:
	-rm -f *.o
	-rm -f *.c
	-rm -f *.js
	-rm -f *.html
	-rm -f *.html.cd
	-rm -f *.html.map
	-rm -f *.debug
	-rm -f *.errors
	-rm -rf *.dSYM
	
%.c: %.sj
	../../sjc $<

timer: timer.c
    ./emcc -g timer.c -o timer.html -s CYBERDWARF=1 -s SAFE_HEAP=1
    
bob: highlow.c
    ./emcc -g highlow.c -o highlow.html -s CYBERDWARF=1 -s SAFE_HEAP=1