# sj

# Development
This will only run on OS X in XCode right now

The xcodeproj is built assuming LLVM will build into a specific relative path, so you need to follow the directory structure.
```
mkdir lang
cd lang
brew install flex
brew install bison
brew install cmake

# From http://llvm.org/docs/GettingStarted.html
git clone http://llvm.org/git/llvm.git
git checkout release_39
cd llvm/tools
git clone http://llvm.org/git/clang.git
git checkout release_39
cd ../..
mkdir install
cd install
pwd # remember this path for below
cd ..
mkdir build
cd build
cmake -G Xcode -DCMAKE_INSTALL_PREFIX=[full path from previous line] ../llvm
cd ..
# Open .xcodeproj
# Do not autocreate schema
# Create new schema, select target: install
# Compile
git clone https://github.com/justinmann/sj.git
# Open .xcodeproj and compile it
```

If you need update the parser
```
cd sj/parser
make
```



