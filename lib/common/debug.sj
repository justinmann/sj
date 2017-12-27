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
