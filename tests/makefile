TARGET = test
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -std=c11
OBJECTS = $(patsubst %.c, %.o, $(wildcard basic/*.c)) $(patsubst %.c, %.o, $(wildcard app/*.c))
HEADERS = $(wildcard *.h)

.PHONY: default all clean
.PRECIOUS: $(TARGET) $(OBJECTS)

all: default

default: $(TARGET)

clean:
	-rm -f app/*.o
	-rm -f basic/*.o
	-rm -f $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $< -Wall $(LIBS) -o $@