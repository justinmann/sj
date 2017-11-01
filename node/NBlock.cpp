#include "Node.h"

void NBlock::defineImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunctionDefinition> thisFunction) {
    assert(compiler->state == CompilerState::Define);
    for (auto it : statements) {
        it->define(compiler, result, thisFunction);
    }
}

shared_ptr<CVar> NBlock::getVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state == CompilerState::FixVar);
    shared_ptr<CVar> lastVar = nullptr;
    for (auto it : statements) {
        lastVar = it->getVar(compiler, result, thisFunction, thisVar);
    }
    return lastVar;
}

shared_ptr<CType> NBlock::getTypeImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar) {
    assert(compiler->state >= CompilerState::FixVar);
    if (statements.size() == 0) {
        return compiler->typeVoid;
    }
    return statements.back()->getType(compiler, result, thisFunction, thisVar);
}

int NBlock::setHeapVarImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, bool isHeapVar) {
    auto count = 0;
    for (auto it : statements) {
        auto isLast = it == statements.back();
        count += it->setHeapVar(compiler, result, thisFunction, thisVar, isLast ? isHeapVar : false);
    }
    return count;
}

shared_ptr<CType> NBlock::transpile(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, TrOutput* trOutput, TrBlock* trBlock, stringstream& trLine) {
	for (auto it : statements) {
		stringstream currentLine;
		it->transpile(compiler, result, thisFunction, thisVar, trOutput, trBlock, currentLine);
		trBlock->statements.push_back(currentLine.str());
	}
    
    if (trBlock->statements.size() > 0) {
        trLine << trBlock->statements.back().line;
        trBlock->statements.pop_back();
    }
    
	return nullptr;
}


//shared_ptr<ReturnValue> NBlock::compileImpl(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, Value* thisValue, IRBuilder<>* builder, BasicBlock* catchBB, ReturnRefType returnRefType) {
//    assert(compiler->state == CompilerState::Compile);
//    shared_ptr<ReturnValue> last = nullptr;
//    for (auto it : statements) {
//        auto isLast = it == statements.back();
//        last = it->compile(compiler, result, thisFunction, thisVar, thisValue, builder, catchBB, isLast ? returnRefType : RRT_Auto);
//        if (!isLast && last) {
//            last->releaseIfNeeded(compiler, result, builder);
//        }
//    }
//    return last;
//}

void NBlock::dump(Compiler* compiler, CResult& result, shared_ptr<CBaseFunction> thisFunction, shared_ptr<CVar> thisVar, map<shared_ptr<CBaseFunction>, string>& functions, stringstream& ss, int level) {
    ss << "{\n";
    for (auto it : statements) {
        stringstream line;
        it->dump(compiler, result, thisFunction, thisVar, functions, line, level + 1);
        auto t = line.str();
        if (t.size() > 0) {
            dumpf(ss, level + 1);
            ss << t << "\n";
        }
    }
    dumpf(ss, level);
    ss << "}";
}
