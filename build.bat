@echo off

set PATH=C:\Program Files\mingw-w64\x86_64-5.3.0-win32-seh-rt_v4-rev0\mingw64\bin;%PATH%

mingw32-make --makefile Makefile.win build

pause
