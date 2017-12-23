package debug {
	write(data : 'string)'void {
		--c--
##ifdef _WINDOWS
        OutputDebugStringA((char*)data->data.data);
##else
		fprintf(stderr, "%s", (char*)data->data.data);
##endif
		--c--
	}

	writeLine(data : 'string)'void {
		--c--
##ifdef _WINDOWS
        OutputDebugStringA((char*)data->data.data);
        OutputDebugStringA("\n");
##else
		fprintf(stderr, "%s\n", (char*)data->data.data);
##endif
		--c--
	}
}