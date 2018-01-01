TARGET = test
LIBS = -lm
CC = gcc
BASIC_OBJECTS =  $(subst basic,basic/binary,$(patsubst %.sj, %, $(wildcard basic/*.sj)))
APP_OBJECTS = $(subst app,app/binary,$(patsubst %.sj, %, $(wildcard app/*.sj)))

ifeq ($(mode),release)
	CFLAGS = -g -O3 -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -I.. -std=c99
else
	mode = debug
	CFLAGS = -g -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -I.. -std=c99
endif

.PHONY: default all clean
.PRECIOUS: $(APP_OBJECTS) app/cfiles/%.c app/debug/%.debug app/errors/%.error $(BASIC_OBJECTS) basic/cfiles/%.c basic/debug/%.debug basic/errors/%.error

all: default

default: app basic

clean: clean-app clean-basic

clean-app:
	-rm -f app/cfiles/*.c
	-rm -f app/errors/*.error
	-rm -f app/debug/*.debug
	-rm -f app/binary/*

app: $(APP_OBJECTS)

app/cfiles/%.c: app/%.sj
	../sjc $^ --c-file=$@ --debug --debug-file=$(subst app/cfiles,app/debug,$(patsubst %.c,%.debug,$@)) --error-file=$(subst app/cfiles,app/errors,$(patsubst %.c,%.error,$@))

app/binary/%: app/cfiles/%.c
	$(CC) $^ $(CFLAGS) -I/mingw64/include/freetype2 -I/mingw64/include/SDL2 -L/mingw64/lib -Dmain=SDL_main -DWIN32 -lmingw32 -lSDL2main -lSDL2 -llibpng16 -lopengl32 -lfreetype -lglew32 -lglu32 -o $@
	
clean-basic:
	-rm -f basic/cfiles/*.c
	-rm -f basic/errors/*.error
	-rm -f basic/debug/*.debug
	-rm -f basic/binary/*

basic: $(BASIC_OBJECTS)

basic/cfiles/%.c: basic/%.sj
	../sjc $^ --c-file=$@ --debug --debug-file=$(subst basic/cfiles,basic/debug,$(patsubst %.c,%.debug,$@)) --error-file=$(subst basic/cfiles,basic/errors,$(patsubst %.c,%.error,$@))

basic/binary/%: basic/cfiles/%.c
	if [ -f $^ ]; then $(CC) $(CFLAGS) $^ -o $@; fi

