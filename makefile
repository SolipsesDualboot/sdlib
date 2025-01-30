CC	=	gcc
SRC	=	src/* -Wall -Wextra
BIN	=	-o bin/bin
INCLUDES=	-I ./include


default: NOTARGET


## windows Windows WINDOWS:
##	$(GCC) $(SRC) $(BIN)


##linux Linux LINUX:
##	$(GCC) $(SRC) $(BIN)

build Build BUILD:
	$(CC) $(SRC) $(BIN)


doxygen Doxygen DOxygen DOXYGEN doc Doc DOC docs Docs DOCS:
	doxygen doc/Doxyfile


NOTARGET:
	printf "\nPlease specify a target when using 'make'; 'LINUX' or 'WINDOWS'\n"
