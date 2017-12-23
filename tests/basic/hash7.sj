include "lib/common/common.sj"

a : {
    "hi" : "hello"
    "bye" : "good bye"
}

debug.writeLine(a["hi"]?:"empty" + a.count.asString())

a.remove("bye")

debug.writeLine(a["hi"]?:"empty" + a.count.asString())

a.remove("hi")

debug.writeLine(a["hi"]?:"empty" + a.count.asString())