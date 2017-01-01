server: rest(
	routes: [
		route(
			method: 'GET'
			path: 'person/{personId'long}'
			callback: logic.person.get
		)
	]
)

model: (
	person(
		name: empty'string
	)
)

logic: (
	person: (
		get(personId'long):person {
			db.connect((connection) {
				connection.select(
					sql: 'SELECT * FROM person WHERE id={id}',
					params: ( 'id': person )
				).single().map {
					model.person(
						name: _.'name'
					)
				}
			})
		}
	)
)

-- database
db: (
	connection(
		select(sql'string, params'map<string, object>):stream<row> {

		}		
	)

	connect(callback'block<connection>) {

	}
)



-- route parsing
route(
	method : empty'string
	path : empty'string
	callback : empty'ref block
	regex : empty'regex
	pathParameters : map<string, type>
) {
	regex : regex(path)
}

rest(
	routes: []
) {
	http.request = (request) {
		route: routes.find({
			_.method == request.method &&
			_.regex.match(request.path)
		})

		if (route != null) {
			valuesAsString: route.regex.value(request.path)
			valuesAsType: valuesAsString.mapValue {
				type: route.pathParameters.get(_.key)
				type.convert(_.value)
			}
			callback.call(valuesAsType)
		}
	}
}