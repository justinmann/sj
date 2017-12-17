halt(reason : 'string) {
	--c--
	halt("%s\n", (char*)data->data.data);
	--c--
}

--cdefine--
void halt(const char * format, ...);
--cdefine--

--cfunction--
void halt(const char * format, ...) {
	char s[1024];
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
##ifdef _DEBUG
	getchar();
##endif
	exit(-1);
}
--cfunction--