#include <stdio.h>

extern "C" void global();

int main() {
	printf("hello\n");
	global();
}

extern "C" void throwException() {
}

extern "C" void debugFunction() {
}
