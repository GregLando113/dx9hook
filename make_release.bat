@echo off
call vcvarsall
cl /c src\dx9hook_base.cpp
lib -nologo -out:dx9hook.lib *.obj lib\d3d9.lib
del *.obj
