-- File format
include
namespace
define
*code*

include [
	'classes.sj'
]
namespace [
	'classes'
]
define [
	myClass [		myProperty: int
	]
]
myClass {
	myProperty: 5
}

-- Simple hierarchy of elements w/ properties
*class*: *baseClass*, *baseClass2* {
	*prop* = *value*
	*function*(*parameters*):*return* { *code* }
} [ *elements*
	*class*
]

controls.page {
	title: 'hello world'
} [
	controls.panel { layout: horizontal } [
		controls.button {
			click() { show('hi') }
			push(a: string, b: int): string { a + b }
		}
	]
]

-- Class definition
define [
	controls [
		page {
			title: string,
		},
		panels {
			layout: enum [ horizontal, vertical ]
		} [
			table {
				columns: array { type: column }
			}
		]
		button {
			val v1: int = 5								// A property that can only set before "create"
			var v2: int = 6								// A property that can change value
			dyn v3: int = 7								// A property that invalidate its parent and can define a custom getter/setter
			val click: () = { show("bye") } 			// method w/ default implementation
			public push(a: string, b: int)				// abstract method, must be define when instantiated
			secret method1() {}
			static method2() {}
			secret static method3() {}			
		}
	]
]

-- Include files
include [ 
	'ui/button.sj', 
	'page.sj', 
	'http://foo.com/things.sj'
]

-- Namespace manipulation
namespace [
	'controls',  								// All code after this does not require the "control." prefix
	'controls.panels' = 'p',					// "p.table" means "control.panels.table"
	'controls.button'							// "method2()" means "controls.button.method2()", this allows calling public static methods without the class name
]

-- Lambda
console {
	main() {
		val list = int [1, 2, 3]
		list.find((n) { n == 2 })

		var button = button { }
		button.push = (a: string, b: int) { a + b }
	}
}

-- Basic types
int
string
char
bool
double
guid
object
array

-- Objects
id: guid										// GUID generated on first request
refCount: int
parent: object									// Automatically set when an object is added to an array, if in two arrays then last one wins		
index: int										// Automatically set when added to an array, last add wins
type: type										// Type is a special object used for reflection, cannot be changed
parentTypes: type								// Type of base class, cannot be changed
childType: type									// Defines the valid type for all objects in the array
invalidate()									// Invokes listener.each((n) { n.invalidate() }), automatically invoked whenever a property is set
listeners: (o: object) []						// Array of weak references to objects
track(o: object)								// Add object to listeners
untrack(o: object)								// Remove object from listeners
create()										// Called after all initial properties & function have been set
destroy()										// Called when all references are gone
release()
properties										// Properties are defined by name and new properties can be attached at any time
functions										// Functions can be attached after creation
array: childType []								// List of objects derived from childType, default childType is 'object'
fromString(s: string): type
toString(): string

-- Arrays
int [1, 2, 3]									// Array of integers
object [object {}, button {}]					// Array of object or anything derived from object

-- Enum
// Enum is not an intrinsic type, but can be simulated by creating a class
colors: enum [ blue, yellow]
// Will convert to
colors {
	val blue: int = 0,
	val yellow: int = 1
}

-- Async
var b = async (b: bool): int { doSomethingSlow() }
b.result										// Waits for async task to complete
task [b, c, d].result 							// Waits for multiple tasks to complete
var c = b.next = () { doAnotherThing() }		// If task is complete runs function immediately, else waits until task is complete and executes next, next returns another task
c.result

-- Actors (aka object messaging)
var b = button {}
val r = b!push("hi", 5)							// Calling a method with '!' instead of '.' means queue the function call and execute as async task, this will return a task
r.result

-- Immutable values
val c = button {}
c.push("bye", 12)								// If the push method tries to modify any properties then it will throw an exception

-- Observable pattern
define [
	button {
		dyn text: title
		render() {
			draw(text)							// Invoke text.get()
		}
	}
]

var b = button {}
b.title = 'hi'									// If title is defined then calls title.set, else create a dyn { get() { 'hi '}} 
b.title = () { 'hi' + 5 }						// Shorthand for dyn { get() { 'hi' + 5 }}
b.title = dyn {									// Full definition, on assignment b will call track(b) so it the dyn can invalidate the object
	var j = ''
	get() { j + 5 }
	set(t: string) { j = t; invalidate() }
}

-- Stylesheets
// Style can set any property on an object
// Style can derive from another style
// Style is defined by type and name
// Finding a style, find style by name on type, then look at base class, etc.
style [
	button {
		'default' = {
			frame = [
				box {
					padding = '4 5 6 0'
					color = parent.color 
				} [
					panel = {
						children: parent.children
					}
				]
			]
		}
		'dark' : 'default' = {
			color = 'blue'
		}
	}
]
button {
	style = 'dark'
}


val p: padding = '4, 5, 6, 7' * 8

-- Automatic string parsing
// Will invoke the fromString static method on Padding
val padding: Padding = '4,6,7,8'

-- Null


-- Templates
// Technically not built-in, but val properties can be used
list {
	val type: Type
	check(i: int): type
}

val q = list { type = button.type }
q.check(0)

-- References
// All objects are released when they leave the scope where the var/val is defined
{
	var j = object {}			// assignment of new object does not addref since object defaults to refCount of 1
	var q = j					// q.refCount++
} 								// q.release, j.release


