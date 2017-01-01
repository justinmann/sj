prop :# <valueType> (
	v = required#valueType

	get :# ()#valueType {
		v
	}

	set :# (value#valueType) {
		v = value
		listeners.each() {
			_(parent.parent, v)
		}
	}

	listeners : array<(object, object)>()
)

classA :# (
	name : prop<int>(0)
	
	// override the set operation for validation
	date : prop<time>(
		v = empty#time,
		set :# (value#valueType) {
			if (value < today)
				throw "error"
			base
		}
	)

	// override the get & set and store the value somewhere else
	age : prop<time>(
		v = empty#time,
		get :# () {
			parent.parent.date.get() - time.now()
		}
		set :# (value#valueType) {
			parent.parent.date.set(value + time.now())
		}
	)
)

a : classA()
a.listeners.push((class, value) {
	// track when prop changes
})
a.name.set(1)
b : a.name.get()