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
	../../sjc $^ --c-file=$@ --debug --debug-file=$(subst cfiles,debug,$(patsubst %.c,%.debug,$@)) --error-file=$(subst cfiles,errors,$(patsubst %.c,%.error,$@))

binary/%: cfiles/%.c
	$(CC) $^ $(CFLAGS) -I/usr/local/include/freetype2 -I/usr/local/include -L/usr/local/lib -lSDL2main -lSDL2 -lpng16 -lfreetype -framework OpenGL -o $@
#	$(CC) $^ $(CFLAGS) -I/mingw64/include/freetype2 -I/mingw64/include/SDL2 -L/mingw64/lib -Dmain=SDL_main -DWIN32 -lmingw32 -lSDL2main -lSDL2 -llibpng16 -lopengl32 -lfreetype -lglew32 -lglu32 -o $@

