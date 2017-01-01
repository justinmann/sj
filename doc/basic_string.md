string :# array<char>(
	from(int) :# (value#int)string
	from(bool) :# (value#bool)string
	from(float) :# (value#float)string
	from(double) :# (value#double)string
)

--
'hi'
"hi"
'hi'.concat("hi")
'hi'.subarray(0, 10)
'hi'.take(1)