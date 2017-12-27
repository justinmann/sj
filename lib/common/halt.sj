halt(reason : 'string) {
    --c--
    halt("%s\n", (char*)reason->data.data);
    --c--
}