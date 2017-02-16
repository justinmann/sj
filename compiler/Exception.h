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
    Function* getDeleteException();
    Function* getUnwindResume();
    Function* getBeginCatch();
    Function* getEndCatch();
    
private:
    LLVMContext* context;
    Module* module;
    Function* raiseException;
    Function* personality;
    Function* deleteException;
    Function* unwindResume;
    Function* beginCatch;
    Function* endCatch;
    Value* sjExceptionType;
};

#endif /* Exception_h */
