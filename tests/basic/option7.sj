class(x : 0) { this }

a : empty'i32
b : a?? as string
c : empty'class
d : c??.x as string

console.writeLine(b)
console.writeLine(d)