//
//  Exception.h
//  sj
//
//  Created by Mann, Justin on 12/25/16.
//  Copyright © 2016 Mann, Justin. All rights reserved.
//

#ifndef Exception_h
#define Exception_h

class Exception
{
public:
    Exception(LLVMContext* context, Module* module);
    Function* getRaiseException();
    Function* getPersonality();
    
private:
    LLVMContext* context;
    Module* module;
    Function* raiseException;
    Function* personality;
    Value* sjExceptionType;
};

#endif /* Exception_h */
