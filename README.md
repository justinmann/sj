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

cd ~
mkdir src
cd src
git clone https://github.com/justinmann/sj.git
cd sj
git submodule init
git submodule update
```
4) Open VS Code and select folder c:\msys64\home\\%USERNAME%\\src\sj
5) Run build task (Ctrl+Shift+B)

## OS/X
1) Open sjc.xcodeproj
2) Compile
3) Open layout.xcodeproj in the "test\app\xcode" folder

## Linux
1) Run make

