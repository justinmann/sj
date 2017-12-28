package debug {
    write(data : 'string)'void {
        data.nullTerminate()
        --c--
        debugout("%s", (char*)data->data.data);
        --c--
    }

    writeLine(data : 'string)'void {
        data.nullTerminate()
        --c--
        debugout("%s\n", (char*)data->data.data);
        --c--
    }
}
