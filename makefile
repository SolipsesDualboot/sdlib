CC	=	gcc
SRC	=	src/*.c -Wall -Wextra -Wpedantic
BIN	=	-o ./bin/bin
INCLUDES=	-I ./include


default: NOTARGET


## windows Windows WINDOWS:
##	$(GCC) $(SRC) $(BIN)


##linux Linux LINUX:
##	$(GCC) $(SRC) $(BIN)

build Build BUILD:
	$(CC) $(SRC) -S
	mv *.s ./bin
	$(CC) bin/*.s $(BIN)


doxygen Doxygen DOxygen DOXYGEN doc Doc DOC docs Docs DOCS:
	doxygen doc/Doxyfile


NOTARGET:
	printf "\nPlease specify a target when using 'make'; 'DOXYGEN' and or 'BUILD'\n"
