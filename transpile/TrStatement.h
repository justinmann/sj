#pragma once

class TrBlock;

class TrStatement {
public:
    TrStatement(string line_) : line(line_) { }
    TrStatement(string line_, shared_ptr<TrBlock> block_) : line(line_), block(block_) { }

    string line;
    shared_ptr<TrBlock> block;
    shared_ptr<TrBlock> elseBlock;
};
