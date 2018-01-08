#writer2(
    write(s : 'string)'void
)

consoleWriter2 #writer2(
    write(s : 'string) {
        console.write(s)
        void
    }
) { this }

c : consoleWriter2() as #writer2
c.write("hello")