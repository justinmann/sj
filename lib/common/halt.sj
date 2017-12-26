halt(reason : 'string) {
    --c--
    halt("%s\n", (char*)reason->data.data);
    --c--
}

--cdefine--
void halt(const char * format, ...);
--cdefine--

--cfunction--
void halt(const char * format, ...) {
    va_list args;
    va_start(args, format);
    debugoutv(format, args);
    va_end(args);
##ifdef _DEBUG
    printf("\npress return to end\n");
    getchar();
##endif
    exit(-1);
}
--cfunction--