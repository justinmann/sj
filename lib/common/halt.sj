halt(reason : 'string) {
    reason.nullTerminate()
    --c--
    halt("%s\n", (char*)reason->data.data);
    --c--
}