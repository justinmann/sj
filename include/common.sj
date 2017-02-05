include "list.sj"

random: ^(
    extern("random_nextInt")    nextInt()'int
    extern("random_nextFloat")  nextFloat()'float
) { this }

console: ^(
    extern("console_readLine")  readLine()'list!char
    extern("console_write")     write(str :' list!char)'void
) { this }

parse: ^(
    extern("parse_toInt")       toInt(str :' list!char)'int
) { this }
