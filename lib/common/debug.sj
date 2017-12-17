package debug {
	write(data : 'string)'void {
		--c--
		printf("%s", (char*)data->data.data);
		--c--
	}

	writeLine(data : 'string)'void {
		--c--
		printf("%s\n", (char*)data->data.data);
		--c--
	}
}