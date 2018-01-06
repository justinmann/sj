class(x : 0) { this }

a : empty'i32
b : a??
c : empty'class
d : c??

console.writeLine(b.asString())
console.writeLine(d.x.asString())