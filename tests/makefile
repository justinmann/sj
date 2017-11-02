TARGET = test
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -std=c11
OBJECTS = $(patsubst %.c, %.o, $(wildcard basic/*.c))
HEADERS = $(wildcard *.h)

.PHONY: default all clean
.PRECIOUS: $(TARGET) $(OBJECTS)

all: default

default: $(TARGET)

clean:
	-rm -f basic/*.o
	-rm -f $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $< -Wall $(LIBS) -o $@