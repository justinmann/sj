TARGET = test
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -Wno-incompatible-pointer-types -std=c11
BASIC_OBJECTS = $(patsubst %.c, %.o, $(wildcard basic/*.c))
APP_OBJECTS = $(patsubst %.c, %.o, $(wildcard app/*.c))
HEADERS = $(wildcard *.h)

.PHONY: default all clean
.PRECIOUS: $(APP_OBJECTS) $(BASIC_OBJECTS)

all: default

default: app basic

app: $(APP_OBJECTS)

basic: $(BASIC_OBJECTS)

clean:
	-rm -f app/*.o
	-rm -f basic/*.o

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
