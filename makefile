TARGET = sjc
LIBS = -lm
CC = g++
CFLAGS = -g -Wall -std=c++11 -I. -Wno-reorder
OBJECTS = $(patsubst %.cpp, %.o, $(wildcard node/*.cpp)) $(patsubst %.cpp, %.o, $(wildcard compiler/*.cpp)) $(patsubst %.cpp, %.o, $(wildcard transpile/*.cpp)) parser/parser.o parser/tokens.o main.o
HEADERS = $(wildcard *.h)

.PHONY: default all clean
.PRECIOUS: $(TARGET) $(OBJECTS)

all: default

default: $(TARGET)

clean:
	-rm -f transpile/*.o
	-rm -f compiler/*.o
	-rm -f parser/*.o
	-rm -f node/*.o
	-rm -f $(TARGET)
	-rm -f parser/parser.cpp parser/parser.hpp parser/tokens.cpp

clean-win:
	-del transpile\*.o
	-del compiler\*.o
	-del parser\*.o
	-del node\*.o
	-del $(TARGET)
	-del parser\parser.cpp parser\parser.hpp parser\tokens.cpp

install:
	cp sjc.exe /usr/bin

parser/parser.cpp: parser/parser.y
	bison -v -d -l -o $@ $^
	
parser/parser.hpp: parser/parser.cpp

parser/tokens.cpp: parser/tokens.l 
	flex -L -o $@ $^

sjc.h.gch : sjc.h
	$(CC) $(CFLAGS) -c sjc.h -o sjc.h.gch

%.o: %.cpp $(HEADERS) sjc.h.gch
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@ -lboost_system-mt -lboost_filesystem-mt -lboost_program_options-mt