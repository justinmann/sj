@echo off
pushd %1
for /f %%f in ('dir /b *.sj') do (
	echo Compiling %%f
	..\..\sjc.exe %%f --debug --no-lines > %%~nf.errors 2>&1
	type %%~nf.errors
)
popd