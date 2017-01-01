#include "nodes/node.h"

/*** TODO:
 
 get code from console
 get code from file
 compile to binary
 
 ***/

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

void testFunction() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("func() { 1 }");
    assert(result->type == RESULT_VOID);

    result = compiler.run("func() { 1 }; func()");
    assert(result->type == RESULT_INT && result->iResult == 1);

    result = compiler.run("func() { func() }");
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
}

void testClass() {
    shared_ptr<CResult> result;
    Compiler compiler;
    
    result = compiler.run("class(x: 0) { this }");
    assert(result->type == RESULT_VOID);
    
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
}

void test() {
    //for (int i = 0; i < 10000; i++)
    {
        testMath();
        testComparison();
        testVoid();
        testCast();
        testParser();
        testAssignment();
        testIf();
        testFunction();
        testClass();
    }
}

int main(int argc, char **argv) {
    /*shared_ptr<CResult> result;
    Compiler compiler;

    result = compiler.run("class(x: 0) { this }\n"
                          "c: class()\n"
                          "c.x");
    assert(result->type == RESULT_INT && result->iResult == 1);
*/
    test();
	return 0;
}
