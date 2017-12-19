include "lib/common/common.sj"

a : {
	"hi" : "hello"
	"bye" : "good bye"
}

debug.writeLine(a["hi"]?:"empty" + a.count.toString())

a.remove("bye")

debug.writeLine(a["hi"]?:"empty" + a.count.toString())

a.remove("hi")

debug.writeLine(a["hi"]?:"empty" + a.count.toString())