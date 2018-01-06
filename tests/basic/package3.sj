#writer(
    write(s : 'string)'void
)

consoleWriter #writer(
    write(s : 'string) {
        console.write(s)
        void
    }
) { this }

c : consoleWriter() as #writer
c.write("hello")