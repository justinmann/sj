They are two types of assignment
":" immutable, not ref counted, stored within parent object
"=" mutable, ref counted, stored in heap

-- convert "=" to ":" or from ":" to "="
Since the two types of references are stored in different parts of memory, the only option is to copy the data
a = classA(5)
b : copy(a)
or
a : classA(5)
b = copy(a)


