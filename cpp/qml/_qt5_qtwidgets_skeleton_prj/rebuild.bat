rmdir /S /Q debug
rmdir /S /Q release
del .qmake.stash
del Makefile
del Makefile.Debug
del Makefile.Release

qmake
mingw32-make
