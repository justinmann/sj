#pragma once

class TrBlock;

class TrStatement {
public:
    TrStatement(string line_) : line(line_), fromCCode(false) { }
    TrStatement(string line_, bool fromCCode) : line(line_), fromCCode(fromCCode) { }
    TrStatement(string line_, shared_ptr<TrBlock> block_) : line(line_), block(block_), fromCCode(false) { }

    string line;
    shared_ptr<TrBlock> block;
    shared_ptr<TrBlock> elseBlock;
    bool fromCCode;
};
