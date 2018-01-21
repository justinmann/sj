TARGET = test
LIBS = -lm
CC = gcc
OBJECTS =  $(addprefix binary/,$(patsubst %.sj, %, $(wildcard *.sj)))

ifeq ($(mode),release)
	CFLAGS = -g -O3 -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -Wno-unused-function -I. -std=c99
else
	mode = debug
	CFLAGS = -g -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -Wno-unused-function -I. -std=c99
endif

.PHONY: default all clean
.PRECIOUS: $(OBJECTS) cfiles/%.c debug/%.debug errors/%.error

all: default

default: $(OBJECTS)

clean: 
	-rm -f cfiles/*.c
	-rm -f errors/*.error
	-rm -f debug/*.debug
	-rm -f binary/*

cfiles/%.c: %.sj
	../sjc $^ --c-file=$@ --debug --debug-file=$(subst cfiles,debug,$(patsubst %.c,%.debug,$@)) --error-file=$(subst cfiles,errors,$(patsubst %.c,%.error,$@))

binary/%: cfiles/%.c
	if [ -f $^ ]; then $(CC) $(CFLAGS) $^ -o $@; fi

