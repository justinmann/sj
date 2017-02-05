#include "node/node.h"

void testMath() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("9223372036854775807");
    assert(result->type == RESULT_INT && result->iResult == 9223372036854775807);

    result = compiler.run("92233720368547758070");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::InvalidNumber);

    result = compiler.run("4 + 5");
    assert(result->type == RESULT_INT && result->iResult == 9);
    
    result = compiler.run("4.0 + 5.0");
    assert(result->type == RESULT_FLOAT && result->fResult == 9.0);
    
    result = compiler.run("-4 + 5");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run("4 + -5");
    assert(result->type == RESULT_INT && result->iResult == -1);
    
    result = compiler.run("4 + 5.0");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);
}

void testComparison() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("true");
    assert(result->type == RESULT_BOOL && result->bResult == true);
    
    result = compiler.run("false");
    assert(result->type == RESULT_BOOL && result->bResult == false);

    result = compiler.run("-3 < 4");
    assert(result->type == RESULT_BOOL && result->bResult == true);

    result = compiler.run("-3 > 4");
    assert(result->type == RESULT_BOOL && result->bResult == false);

    result = compiler.run("-3 <= 4");
    assert(result->type == RESULT_BOOL && result->bResult == true);

    result = compiler.run("4 <= 4");
    assert(result->type == RESULT_BOOL && result->bResult == true);

    result = compiler.run("-3 >= 4");
    assert(result->type == RESULT_BOOL && result->bResult == false);

    result = compiler.run("4 >= 4");
    assert(result->type == RESULT_BOOL && result->bResult == true);

    result = compiler.run("-3 == 4");
    assert(result->type == RESULT_BOOL && result->bResult == false);

    result = compiler.run("-3 != 4");
    assert(result->type == RESULT_BOOL && result->bResult == true);
    
    result = compiler.run("-3.0 < 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == true);
    
    result = compiler.run("-3.0 > 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == false);
    
    result = compiler.run("-3.0 <= 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == true);
    
    result = compiler.run("4.0 <= 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == true);
    
    result = compiler.run("-3.0 >= 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == false);
    
    result = compiler.run("4.0 >= 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == true);
    
    result = compiler.run("-3.0 == 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == false);
    
    result = compiler.run("-3.0 != 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == true);

    result = compiler.run("!true");
    assert(result->type == RESULT_BOOL && result->bResult == false);

    result = compiler.run("!(-3.0 != 4.0)");
    assert(result->type == RESULT_BOOL && result->bResult == false);
}

void testVoid() {
    shared_ptr<CResult> result;
    Compiler compiler;

    result = compiler.run("void");
    assert(result->type == RESULT_VOID);
}

void testCast() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("5 as float");
    assert(result->type == RESULT_FLOAT && result->fResult == 5.0);

    result = compiler.run("5.0 as int");
    assert(result->type == RESULT_INT && result->iResult == 5);
}


void testParser() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("@");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::InvalidCharacter && result->errors[0].line == 1 && result->errors[0].col == 1);

    result = compiler.run("   @");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::InvalidCharacter && result->errors[0].line == 1 && result->errors[0].col == 4);

    result = compiler.run("\n\n\n\n    @\n");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::InvalidCharacter && result->errors[0].line == 5 && result->errors[0].col == 5);
}

void testAssignment() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("x = 1");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("x'int = 1");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("x'int = 1.0");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);

    result = compiler.run("x = 1; x = 2; x + 1");
    assert(result->type == RESULT_INT && result->iResult == 3);

    result = compiler.run("y : 1; x = 2; x + y");
    assert(result->type == RESULT_INT && result->iResult == 3);

    result = compiler.run("x : 1; x + 1");
    assert(result->type == RESULT_INT && result->iResult == 2);

    result = compiler.run("x : 1; x : 2; x + 1");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::ImmutableAssignment);

    result = compiler.run("x : y : 2");
    assert(result->type == RESULT_INT && result->iResult == 2);

    result = compiler.run("x : y : 2; x + y");
    assert(result->type == RESULT_INT && result->iResult == 4);

    result = compiler.run("a = 0; a++");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("a : 0; a++");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::ImmutableAssignment);

    result = compiler.run("a = 0; a += 1.0");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);

    result = compiler.run("a = 0; a += 1");
    assert(result->type == RESULT_INT && result->iResult == 1);
}

void testComment() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("/* hi */");
    assert(result->type == RESULT_VOID);
    
    result = compiler.run("1/* comment */");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run(R"DELIM(
                          1
    /* 
     ** comment **
     */
                          )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    
    result = compiler.run("// comment\n1");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("1 // comment\n");
    assert(result->type == RESULT_INT && result->iResult == 1);
}

void testIf() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("if true { 1 } else { 2 }");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run("if false { 1 } else { 2 }");
    assert(result->type == RESULT_INT && result->iResult == 2);
    
    result = compiler.run("if false { 1 }");
    assert(result->type == RESULT_INT && result->iResult == 0);
    
    result = compiler.run("if false { 1 } else if true { 2 }");
    assert(result->type == RESULT_INT && result->iResult == 2);
    
    result = compiler.run("if false { 1 } else if false { 2 } else if false { 2 } else if false { 2 } else if false { 2 } else if false { 2 } else if false { 2 } else { 3 }");
    assert(result->type == RESULT_INT && result->iResult == 3);
    
    result = compiler.run("if false { void }");
    assert(result->type == RESULT_VOID);
    
    result = compiler.run("if false { 1 } else { 1.0 }");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);
    
}

void testFor() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("for x: 1 to 10 { }");
    assert(result->type == RESULT_VOID);
    
    result = compiler.run("for x: 1.0 to 10 { }");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);
    
    result = compiler.run("for x: 1 to 10.0 { }");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);
    
    result = compiler.run("x: 1\nfor x: 1 to 10 { }");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::InvalidVariable);
    
    result = compiler.run("y = 0\nfor x: 2 to 4 { y = y + x }\ny");
    assert(result->type == RESULT_INT && result->iResult == 9);

    result = compiler.run("y = 0\nfor x: 2 to 1 { y = y + x }\ny");
    assert(result->type == RESULT_INT && result->iResult == 0);
}

void testWhile() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("while false {}");
    assert(result->type == RESULT_VOID);
    
    result = compiler.run("while 1.0 {}");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);
    
    result = compiler.run("x = 10; while x > 0 { x = x - 1 }; x");
    assert(result->type == RESULT_INT && result->iResult == 0);
}

void testFunction() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("func() { 1 }");
    assert(result->type == RESULT_VOID);

    result = compiler.run("func() { 1 }; func()");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("func() { func() }; func()");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeLoop);

    result = compiler.run("func() { -3.0 }; func() < 4.0");
    assert(result->type == RESULT_BOOL && result->bResult == true);

    result = compiler.run("func(x: 1) { x }; func()");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("func(x: 1) { x }; func(2)");
    assert(result->type == RESULT_INT && result->iResult == 2);

    result = compiler.run("func(x: 1) { x }; func(x: 3)");
    assert(result->type == RESULT_INT && result->iResult == 3);

    result = compiler.run("func(x: 1, y: 2) { x + y }; func(y: 1)");
    assert(result->type == RESULT_INT && result->iResult == 2);

    result = compiler.run("func(x: 1, y: 2) { x + y }; func(2, y: 1)");
    assert(result->type == RESULT_INT && result->iResult == 3);

    result = compiler.run("func(x: 1, y: 2) { x + y }; func(y: 1, 1)");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::ParameterByIndexAfterByName);

    result = compiler.run("func(x: 1, y: 2) { x + y }; func(y: 1, y: 1)");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::ParameterRedefined);

    result = compiler.run("func(x: 1, y: 2) { x + y }; func(q: 1)");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::ParameterDoesNotExist);

    result = compiler.run("func(x: 1, y: 2) { x + y }; func(1, 2, 3)");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TooManyParameters);

    result = compiler.run("func(x: 1, y: 2) { x + y }; func(1.0)");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);

    result = compiler.run("func(x: 'int) { x }; func(1)");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("func(x: 'float) { x }; func(1.0)");
    assert(result->type == RESULT_FLOAT && result->fResult == 1.0);

    result = compiler.run("func(x: 'float) { x }; func(1)");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::TypeMismatch);

    result = compiler.run("func(x: 'int) { x }; func()");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::ParameterRequired);

    result = compiler.run(R"DELIM(
        func(x: 'int)'int {
            if x > 0 {
                func(x - 1)
            } else {
                0
            }
        }
        func(4)
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 0);

    result = compiler.run(R"DELIM(
        bar() { 9 }
        func() {
            bar()
        }
        func()
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 9);

    result = compiler.run(R"DELIM(
        func(
            bar() { 9 }
        ) {
            bar()
        }
        func()
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 9);

    result = compiler.run(R"DELIM(
		foo() {
			void
		}
		foo()
    )DELIM");
    assert(result->type == RESULT_VOID);
}

void testClass() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("class(x: 0) { this }");
    assert(result->type == RESULT_VOID);
    
    result = compiler.run("class(b : 0) { this }; a : class(); a.b = 1");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::ImmutableAssignment);

    result = compiler.run("class(a.b : 0) { this }");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::InvalidDot);
    
    result = compiler.run("class(b = 0) { this }; a : class(); a.b = 1");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("class(x: 0) { this }\n"
                          "c: class()\n"
                          "c.x");
    assert(result->type == RESULT_INT && result->iResult == 0);
    
    result = compiler.run("class(x: 0) { this }\n"
                          "c: class(x: 1)\n"
                          "c.x");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run("class(x: 0) { this }\n"
                          "c: class(1)\n"
                          "c.x");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run("class(x: 0, y: 0) { this }\n"
                          "c: class(1, 2)\n"
                          "c.x + c.y");
    assert(result->type == RESULT_INT && result->iResult == 3);
    
    result = compiler.run("class(func() { 1 }) { this }\n"
                          "c: class()\n"
                          "c.func()");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("class(x:0, func() { x }) { this }\n"
                          "c: class(1)\n"
                          "c.func()");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run(R"DELIM(
        class(x : 0) { this }
        func() { class(1) }
        func().x
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run(R"DELIM(
		class(
			foo(x: 'int) {
				if x > 0 {
					bar(x - 1)
				} else {
					0
				}
			}
			bar(x: 0) {
				foo(x)
			}
		) { this }
		c: class()
		c.foo(4)
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 0);

    result = compiler.run(R"DELIM(
		math(
			sub(x: 'int, y: 'int) {
				x - y
			}
		) { this }
		class(
			m: math()
			foo(x: 0) {
				if x > 0 {
					bar(m.sub(x, 1))
				} else {
					0
				}
			}
			bar(x: 0) {
				foo(x)
			}
		) { this }
		c: class()
		c.foo(4)
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 0);

    result = compiler.run(R"DELIM(
        class() {
			m: 1
			inner() {
				m
			}
			inner()
		}
        class()
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run(R"DELIM(
		math: ^(
                sub(x: 'int, y: 'int) {
				x - y
			}
		) { this }
		class(
			foo(x: 0) {
				if x > 0 {
					bar(math.sub(x, 1))
				} else {
					0
				}
			}
			bar(x: 0) {
				foo(x)
			}
		) { this }
		c: class()
		c.foo(4)
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 0);

    result = compiler.run(R"DELIM(
        a(
            x: 1
            b: aa(
                c() { x }
            ) { this }
        ) { this }
        a: a()
        a.b.c()
        d: a.b
        d.c()
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);
}
                          
void testExtern() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("extern(\"cos\") cos(x:'float)'float\n"
                          "cos(1.0)");
    assert(result->type == RESULT_FLOAT && result->fResult == 0.54030230586813977);
}
                          
void testThrow() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    try {
        result = compiler.run("throw(0)");
        assert(false);
    } catch(SJException& e) { }

    try {
        result = compiler.run("throw(1)");
        assert(false);
    } catch (SJException& e) { }
    
    try {
        result = compiler.run(R"DELIM(
            foo() {
                throw(1)
            }
            foo()
        )DELIM");
        assert(false);
    } catch(SJException& e) { }
    
    result = compiler.run(R"DELIM(
		foo() {
			throw(1)
		}

		bar() {	
			foo()
			1
		} catch {
			2
		}

		bar()
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 2);
}

void testTemplate() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run(R"DELIM(
        class!t() { 1 }
        a: class!int()
        b: class!float()
        c: class!bool()
    )DELIM");
    assert(result->type != RESULT_ERROR);

    result = compiler.run(R"DELIM(
        class!t(
            x:'t
        ) { this }
        c: class!int(1)
        c.x
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run(R"DELIM(
                          class![t1, t2]() { 1 }
                          a: class![int, bool]()
                          c: class![bool, float]()
                          )DELIM");
    assert(result->type != RESULT_ERROR);
    
    result = compiler.run(R"DELIM(
        class!t() { 1 }
        func() { }
        d: class!func()
    )DELIM");
    assert(result->type != RESULT_ERROR);
    
    result = compiler.run(R"DELIM(
                          class![t1, t2]() { 1 }
                          func() { }
                          b: class![float, func]()
                          d: class![func, int]()
                          )DELIM");
    assert(result->type != RESULT_ERROR);
    
    result = compiler.run(R"DELIM(
                          class!t() { 1 }
                          func!t() { 1 }
                          d: class![func!int]()
                          )DELIM");
    assert(result->type != RESULT_ERROR);
    
    result = compiler.run(R"DELIM(
                          class!t(
                                  func!t() { 1 }
                                  ) { this }
                          c: class!int()
                          1
                          )DELIM");
    assert(result->type != RESULT_ERROR);
}
                          
void testArray() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run(R"DELIM(
        a : array!int(1)
        a.set(0, 1)
        c : a.get(0)
        a.delete(1)
        c
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run(R"DELIM(
        class(x: 0) { this }
        a : array!class(1)
        a.set(0, class(1))
        b : a.get(0)
        c : b.x
        a.delete(1)
        c
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);
    
    result = compiler.run(R"DELIM(
        include "list.sj"
        
        a : [1, 2, 3]
        a[0] = 2		// find method 'set'
        a[0]			// find method 'get'
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 2);
    
    result = compiler.run(R"DELIM(
        include "list.sj"
        
        class(x : 'int) { this }
        a : [class(1), class(2), class(3)]
        c : a[0]
        c.x
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 1);
}

void testInclude() {
    shared_ptr<CResult> result;
    Compiler compiler;

    result = compiler.run(R"DELIM(
                          include "list.sj"
                          
                          a : [1]
                          a[0] = 3
                          a[0]
                        )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 3);


    result = compiler.run(R"DELIM(
                          class() {
                              include "list.sj"
                          }
                          )DELIM");
    assert(result->type == RESULT_ERROR && result->errors[0].code == CErrorCode::IncludeOnlyInGlobal);

    result = compiler.run(R"DELIM(
                          include "common.sj"

                          a : [1]
                          a[0] = 3
                          a[0]
                          )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 3);
}

void testString() {
    shared_ptr<CResult> result;
    Compiler compiler;

    result = compiler.run(R"DELIM(
                        include "list.sj"
                          
                          a : "hello"
                          c : a[0]
                          c == 'h'
                        )DELIM");
    assert(result->type == RESULT_BOOL && result->bResult);

    result = compiler.run(R"DELIM(
                          include "list.sj"
                          "hello"
                          )DELIM");
    assert(result->type == RESULT_STR && result->strResult == "hello");

    result = compiler.run("'\n'");
    assert(result->type == RESULT_CHAR && result->cResult == '\n');

    result = compiler.run("'\''");
    assert(result->type == RESULT_CHAR && result->cResult == '\'');

    result = compiler.run(R"DELIM(
                          include "list.sj"
                          "he\nllo"
                          )DELIM");
    assert(result->type == RESULT_STR && result->strResult == "he\nllo");

    result = compiler.run(R"DELIM(
                          include "list.sj"
                          "he\"llo"
                          )DELIM");
    assert(result->type == RESULT_STR && result->strResult == "he\"llo");
}

void testHeap() {
    shared_ptr<CResult> result;
    Compiler compiler;

    result = compiler.run(R"DELIM(
                          bar(f = foo(1)) { this }
                          foo(x : 0) { this }
                          
                          func(b : 'bar) {
                              b.f = foo(2) // callvar("foo") is heap because it is store in a non-local var
                          }
                          
                          b : bar() // callvar("boo") is stack because it is stored in a local var
                          func(b).x
    )DELIM");
    assert(result->type == RESULT_INT && result->iResult == 2);
}
                          
int main(int argc, char **argv) {
    shared_ptr<CResult> result;
    Compiler compiler;

    testMath();
    testComparison();
    testVoid();
    testCast();
    testParser();
    testAssignment();
    testComment();
    testIf();
    testFor();
    testWhile();
    testFunction();
    testClass();
    testExtern();
    testTemplate();
    testArray();
    testInclude();
    testString();
    testHeap();

    // testThrow();
    // compiler.run("include \"highlow.sj\"");

    return 0;
}
