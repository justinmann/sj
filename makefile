TARGET = sjc
LIBS = -lm
CC = g++

ifeq ($(mode),release)
	CFLAGS = -g -O3 -Wall -std=c++11 -Iinclude -Wno-reorder
else
	mode = debug
	CFLAGS = -g -Wall -std=c++11 -Iinclude -Wno-reorder
endif

CFILES = $(wildcard src/*.cpp)
COBJECTS = $(subst src/,build/,$(patsubst %.cpp, %.o, $(CFILES)))
ALLOBJECTS = $(COBJECTS) parser/parser.o parser/tokens.o
HEADERS = $(wildcard include/*.h)

.PHONY: default all clean
.PRECIOUS: $(TARGET) $(OBJECTS)

all: default

default: $(TARGET)

clean:
	-rm -f build/*.o
	-rm -f include/*.gch
	-rm -f $(TARGET)
	-rm -f $(TARGET).exe
	-rm -f parser/parser.cpp parser/tokens.cpp

install:
	cp sjc.exe /usr/bin

parser/parser.cpp: parser/parser.y
	bison -v -d -l -o $@ $^
	
parser/parser.hpp: parser/parser.cpp

parser/tokens.cpp: parser/tokens.l 
	flex -L -o $@ $^

include/sjc.h.gch : $(HEADERS)
	$(CC) $(CFLAGS) -c include/sjc.h -o include/sjc.h.gch

parser/parser.o: parser/parser.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

parser/tokens.o: parser/tokens.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

build/%.o: src/%.cpp include/sjc.h.gch
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(ALLOBJECTS)
	$(CC) $(ALLOBJECTS) -Wall $(LIBS) -o $@ -lboost_system-mt -lboost_filesystem-mt -lboost_program_options-mt