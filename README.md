# sj

## Windows
1) Install vs code: https://code.visualstudio.com/
2) Install msys2: http://www.msys2.org/
2) Add msys2 to path: C:\msys64\mingw64\bin
  * https://superuser.com/questions/284342/what-are-path-and-other-environment-variables-and-how-can-i-set-or-use-them
3) Open msys2 and run:
```
pacman -S git make mingw-w64-x86_64-boost mingw-w64-x86_64-SDL2 
pacman -S bison mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb 
pacman -S mingw-w64-x86_64-freetype mingw-w64-x86_64-libpng mingw-w64-x86_64-glew
```
4) Open VS Code and select the root of your git clone as the folder (make sure to git clone inside of msys2 terminal)
5) Run build task (Ctrl+Shift+B)

## OS/X
1) Install vs code: https://code.visualstudio.com/
1) Install homebrew
1) Enable GDB debugging https://gist.github.com/gravitylow/fb595186ce6068537a6e9da6d8b5b96d
1) Install dependencies from terminal
```
brew install boost sdl2 gdb
```
4) Open VS Code and select the root of your git clone as the folder
5) Run build task (Ctrl+Shift+B)
NOTE: You may get a weird error when you compile with emcc, this should fix it:
```
brew install llvm && rm /usr/local/opt/emscripten/libexec/llvm/bin/llvm-ar && ln -s /usr/local/opt/llvm/bin/llvm-ar /usr/local/opt/emscripten/libexec/llvm/bin/llvm-ar
```

## Linux
1) Install vs code: https://code.visualstudio.com/
