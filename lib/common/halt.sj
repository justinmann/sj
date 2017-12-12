halt(reason : 'string) {
	--c--
	printf("%s\n", (char*)reason->data.data);
	exit(-1);
	--c--
}

--cinclude--
#include(<stdarg.h>)
--cinclude--

--cdefine--
void halt(const char * format, ...);
--cdefine--

--cfunction--
void halt(const char * format, ...) {
  va_list args;
  va_start (args, format);
  vprintf (format, args);
  va_end (args);
  exit(-1);
}
--cfunction--