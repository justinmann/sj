// Single-line comments start with //

/*
Multi-line comments look like this.
*/

///////////////////////////////////////
// Input/Output
///////////////////////////////////////

/*
* Output
*/

// Use console.writeLine() to print lines.
console.writeLine("Hello World!")
console.writeLine(
    "Integer: " + 10 as string + " Double: " + 3.14 as string + " Boolean: " + true as string
)

// To print without a newline, use System.out.print().
console.write("Hello ")
console.write("World")

/*
* Input
*/

name : console.readLine()

// read int input
numInt : name as i32

// read long input
numFloat : name as f32

// read double input
numDouble : name as f64

// read boolean input
numBool : name as bool

///////////////////////////////////////
// Variables
///////////////////////////////////////
/*
*  Variable Initialization
*/

// Initialize a variable using <type> <name> = <val>
barInt : 1

/*
*  Variable types
*/
// char - 8-bit unsigned
// (0 <= char <= 255)
fooChar : '4'

// i32 - 32-bit signed two's complement integer
// (-2,147,483,648 <= i32 <= 2,147,483,647)
bazInt : 1

// i64 - 64-bit signed two's complement integer
// (-9,223,372,036,854,775,808 <= long <= 9,223,372,036,854,775,807)
fooLong : 100000l
// L is used to denote that this variable value is of type Long
// anything without is treated as integer by default.

// Float - Single-precision 32-bit IEEE 754 Floating Point
// 2^-149 <= float <= (2-2^-23) * 2^127
fooFloat : 234.5f
// f or F is used to denote that this variable value is of type float
// otherwise it is treated as double.

// Double - Double-precision 64-bit IEEE 754 Floating Point
// 2^-1074 <= x <= (2-2^-52) * 2^1023
fooDouble : 123.4

// Boolean - true & false
fooBoolean : true
barBoolean : false

// Strings
fooString : "My String Is Here!"

// \n is an escaped character that starts a new line
barString : "Printing on a new line?\nNo Problem!"
// \t is an escaped character that adds a tab character
bazString : "Do you want to add a tab?\tNo Problem!"
console.writeLine(fooString)
console.writeLine(barString)
console.writeLine(bazString)

// String Building
// That's the basic way to do it (optimized under the hood)
plusConcatenated : "Strings can " + "be concatenated " + "via + operator."
console.writeLine(plusConcatenated)
// Output: Strings can be concatenated via + operator.

// Arrays
// If you want to set all elements in array to the same default value
intArray1 : array.create!i32(10, -1)

// Or you can you use the static initializer
intArray2 : [1, 2, 3]

obj() { this }

// Arrays can contain any type, but all elements must have the same type
objArray : [obj(), obj()]

// Indexing an array - Accessing an element
console.writeLine("intArray1 @ 0: " + intArray1[0] as string)

// Arrays are zero-indexed and mutable.
intArray2[1] = 1
console.writeLine("intArray2 @ 1: " + intArray2[1] as string) // => 1

// List - array that can grow
l : list!string()
l.add("hello")
l.add("bye")
l.removeAt(0)

// Hash - a simple key/value hash table
h : hash![string, i32]()
h["bob"] = 1
h["foo"] = 2
h["foo"] = h["bob"]?? + 1

///////////////////////////////////////
// Operators
///////////////////////////////////////
i1 : 1
i2 : 2

// Arithmetic is straightforward
console.writeLine("1+2 = " + (i1 + i2) as string) // => 3
console.writeLine("2-1 = " + (i2 - i1) as string) // => 1
console.writeLine("2*1 = " + (i2 * i1) as string) // => 2
console.writeLine("1/2 = " + (i1 / i2) as string) // => 0 (int/int returns int)
console.writeLine("1/2.0 = " + (i1 as f64 / i2 as f64) as string) // => 0.5

// Modulo
console.writeLine("11%3 = " + (11 % 3) as string) // => 2

// Comparison operators
console.writeLine("3 == 2? " + (3 == 2) as string) // => false
console.writeLine("3 != 2? " + (3 != 2) as string) // => true
console.writeLine("3 > 2? " + (3 > 2) as string) // => true
console.writeLine("3 < 2? " + (3 < 2) as string) // => false
console.writeLine("2 <= 2? " + (2 <= 2) as string) // => true
console.writeLine("2 >= 2? " + (2 >= 2) as string) // => true

// Boolean operators
console.writeLine("3 > 2 && 2 > 3? " + ((3 > 2) && (2 > 3)) as string) // => false
console.writeLine("3 > 2 || 2 > 3? " + ((3 > 2) || (2 > 3)) as string) // => true
console.writeLine("!(3 == 2)? " + (!(3 == 2)) as string) // => true

// Bitwise operators!
/*
~      Unary bitwise complement
<<     Signed left shift
>>     Signed/Arithmetic right shift
>>>    Unsigned/Logical right shift
&      Bitwise AND
^      Bitwise exclusive OR
|      Bitwise inclusive OR
*/

// Increment operators
i := 0
console.writeLine("\n->Inc/Dec-rementation")
// The ++ and -- operators increment and decrement by 1 respectively.
i ++
console.writeLine(i as string) // i = 1, prints 0 (post-increment)
i --
console.writeLine(i as string) // i = 1, prints 2 (post-decrement)

///////////////////////////////////////
// Control Structures
///////////////////////////////////////
console.writeLine("\n->Control Structures")

// If statements are c-like
j : 10
if (j == 10) {
    console.writeLine("I get printed")
} else if (j > 10) {
    console.writeLine("I don't")
} else {
    console.writeLine("I also don't")
}

// While loop
fooWhile := 0
while(fooWhile < 100) {
    console.writeLine(fooWhile as string)
    // Increment the counter
    // Iterated 100 times, fooWhile 0,1,2...99
    fooWhile++
}
console.writeLine("fooWhile Value: " + fooWhile as string)

// For Loop
// for loop structure => for(<start_statement> <conditional> <step>)
for fooFor : 0 to 10 {
    console.writeLine(fooFor as string)
    // Iterated 10 times, fooFor 0->9
}

// For Each Loop
// The for loop is also able to iterate over arrays as well as objects
// that implement the Iterable interface.
fooList : [ 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
// for each loop structure => for (<object> : <iterable>)
// reads as: for each element in the iterable
// note: the object type must match the element type of the iterable.

fooList.each(^{
    console.writeLine(_ as string)
    //Iterates 9 times and prints 1-9 on new lines
})

// Switch Case
// A switch works with the byte, short, char, and int data types.
// It also works with enumerated types (discussed in Enum Types), the
// String class, and a few special classes that wrap primitive types:
// Character, Byte, Short, and Integer.
// Starting in Java 7 and above, we can also use the String type.
// Note: Do remember that, not adding "break" at end any particular case ends up in
// executing the very next case(given it satisfies the condition provided) as well.
month : 3
monthString := ""
switch (month) {
    1 { monthString = "January" }
    2 { monthString = "February" }
    3 { monthString = "March" }
    default { monthString = "Some other month" }
}
console.writeLine("Switch Case Result: " + monthString)

///////////////////////////////////////
// Classes And Functions
///////////////////////////////////////

console.writeLine("\n->Classes & Functions")

// (definition of the Bicycle class follows)

// Use new to instantiate a class
trek : Bicycle()

// Call object methods
trek.speedUp(3) // You should always use setter and getter methods
trek.setCadence(100)

// toString returns this Object's string representation.
console.writeLine("trek info: " + trek.asString())

// Class is a function that returns "this"
func(x : 0, y : 0) { 1 } // Function with two parameters
class(x : 0, y : 0) { this } // Class with two fields

// Class definition for Bicycle
Bicycle(
    // Bicycle's Fields/Variables
    cadence := 50 // Public: Can be accessed from anywhere
    gear := 1
    name := "Bontrager"
    _speed := 5 // Private: Only accessible from within the class (any function/var that starts with _ is private)

    getCadence() {
        cadence
    }

    // void methods require no return statement
    setCadence(newValue : 'i32) {
        cadence = newValue
    }

    setGear(newValue : 'i32) {
        gear = newValue
    }

    speedUp(increment : 'i32) {
        _speed += increment
    }
    
    slowDown(decrement : 'i32) {
        _speed -= decrement
    }

    setName(newName : 'string) {
        name = newName
    }

    getName() {
        name
    }

    //Method to display the attribute values of this Object.
    asString() {
        "gear: " + gear as string + " cadence: " + cadence as string + " speed: " + _speed as string + " name: " + name
    }
) {
    // This is a constructor

    // Must return this to make it into a class
    this
}
// Interfaces

// Example - Food:
#Edible (
    eat()'void // Any class that implements this interface, must implement this method.
)

#Digestible (
    digest()'void
)

// We can now create a class that implements both of these interfaces.
Fruit #Edible #Digestible (
    eat() {
        // ...
        void
    }

    digest() {
        // ...
        void
    }
) { this }

// Enum Type
//
// An enum type is a special data type that enables for a variable to be a set
// of predefined constants. The variable must be equal to one of the values
// that have been predefined for it. For example,
// you would specify a days-of-the-week enum type as:
enum Day(
    SUNDAY
    MONDAY
    TUESDAY
    WEDNESDAY
    THURSDAY 
    FRIDAY
    SATURDAY
)

// We can use our enum Day like that:
EnumTest(
    // Variable Enum
    day : 'Day

    tellItLikeItIs() {
        switch day {
            Day.MONDAY { 
                console.writeLine("Mondays are bad.") 
            }
            Day.FRIDAY {     
                console.writeLine("Fridays are better.") 
            }
            _ == Day.SATURDAY || _ == Day.SUNDAY {
                console.writeLine("Weekends are best.") 
            }
            default {
                console.writeLine("Midweek days are so-so.") 
            }
        }
    }
) { this }


firstDay : EnumTest(Day.MONDAY)
firstDay.tellItLikeItIs() // => Mondays are bad.
thirdDay : EnumTest(Day.WEDNESDAY)
thirdDay.tellItLikeItIs() // => Midweek days are so-so.
