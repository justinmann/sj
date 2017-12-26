package debug {
    write(data : 'string)'void {
        --c--
        debugout("%s", (char*)data->data.data);
        --c--
    }

    writeLine(data : 'string)'void {
        --c--
        debugout("%s\n", (char*)data->data.data);
        --c--
    }
}

--cdefine--
void debugout(const char * format, ...);
void debugoutv(const char * format, va_list args);
--cdefine--

--cfunction--
void debugout(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
}

void debugoutv(const char * format, va_list args) {
##ifdef _WINDOWS
    char text[1024];
    vsnprintf(text, sizeof(text), format, args);
    OutputDebugStringA(text);
##else
    vfprintf(stderr, format, args);
##endif
}
--cfunction--