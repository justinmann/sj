#pragma once

class TrBlock;

class TrStatement {
public:
    TrStatement(CLoc loc, string line_) : loc(loc), line(line_), fromCCode(false) { }
    TrStatement(CLoc loc, string line_, bool fromCCode) : loc(loc), line(line_), fromCCode(fromCCode) { }
    TrStatement(CLoc loc, string line_, shared_ptr<TrBlock> block_) : loc(loc), line(line_), block(block_), fromCCode(false) { }

    CLoc loc;
    string line;
    shared_ptr<TrBlock> block;
    shared_ptr<TrBlock> elseBlock;
    bool fromCCode;
};
