
class(x : 'i32) { this }
a: list!heap class()
for x : 1 to 100000 {
    a.add(item : heap class(x))
}
c : a[0]
c.x