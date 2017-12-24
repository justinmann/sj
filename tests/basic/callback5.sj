include "lib/common/common.sj"

bob(x : 0) { this }

#foo(
    getBar()'bob
)

class #foo (
    bar := 0
    getBar() { bob(bar) }
) { this }

f : weak class() as #foo
cb : f?.getBar
a : cb()
b : heap cb()