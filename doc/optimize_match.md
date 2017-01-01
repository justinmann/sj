findAndRun<j>: (check'(t)'bool, run'(t)'j)'j {	
	counter = 0
@loop
	if (counter >= length) return
	if (block(items[counter])) return run(items[counter])
	counter++
	goto loop
}

match: <t ret>(
	val't 
	[outer] items'array<check<t>>
)'ret {
	items.findAndRun(check: {
		_.check(val)
	}, run: {
		_.result()
	})
}

--
match: <t ret>(
	val't 
	[outer] items'array<check<t>>
)'ret {
	counter = 0
@loop
	if (counter >= length) return
	if (!items[counter].check(val)) return items[counter].result()
	counter++
	goto loop
}

match(a) [
	(_ == 1, 11)
	(_ == 2, 12)
	(_ == 3, a + 13)
]


--
{
	items: [
		(_ == 1, 11)
		(_ == 2, 12)
		(_ == 3, a + 13)
	]

	if (0 >= 3) return
	if (items[0].check(a)) return items[0].result()
	if (1 >= 3) return
	if (items[1].check(a)) return items[1].result()
	if (2 >= 3) return
	if (items[2].check(a)) return items[2].result()
	if (3 >= 3) return
	if (items[3].check(a)) return items[3].result()
}

--
{
	if (a == 1) 
		return 11
	if (a == 2) 
		return 12
	if (a == 3) 
		return a + 13
	return
}