TARGET = sjc
LIBS = -lm
CC = g++
CFLAGS = -g -Wall -std=c++11
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

parser/parser.cpp: parser/parser.y
	bison -v -d -l -o $@ $^
	
parser/parser.hpp: parser/parser.cpp

parser/tokens.cpp: parser/tokens.l 
	flex -L -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@