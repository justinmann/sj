-- model.sj
model : (
	person(
		name = empty'string
	)

	people = list<person>()
) {
	people.add(person(name = 'Bob'))
	people.add(person(name = 'Sue'))
}

-- view.sj
button (
	title = empty'string
) 

home : repeater<person, panel> {
	data ~ model.people
	template = {
		panel [
			button (
				title ~ _.name		// one-way bind   like this bind(this, field(this.title), _, field(_.name))
			)
			edit (
				text ~~ _.name		// two-way binding
			)
		]
	}
}

-- main.sj
window (
	view = home()
)


bind(destObject'ref object, destField'ref field, srcObject'ref object, srcField'ref field) {
	destField.set(destObject, srcField.get(srcObject))
	destObject.changes.add((field, newValue) {
		if (field == srcField) {
			destField.set(destObject, newValue)
		}
	})
}


repeater<dataType, viewType> (
	data'list<dataType>
	template'(dataType)'viewType
) {
	
}