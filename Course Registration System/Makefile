# Sample generic makefile (Makefile or makefile are both found by gcc)
# Prof. Frank Emanuel (2022)

# Variables 
# Note: = is assign; := is expand before assigning; += is append;
# ?= is only assign if not already defined; != expands and runs the command
# shell assigning the results to the variable.

SRC := Header.h InitializeArray.c PrintInform.c Lab3.c StuAndCourseRegis.c
OBJ := $(SRC:.c=.o)
BIN := Lab3
CFLAGS ?= -ansi -pedantic -Wall -g -w

# Recipes
# Recipes follow this pattern:
# target: dependencies
# <tab>recipe
# <tab>recipe...
# Note that makefiles are highly whitespace sensitive (think python)
#

$(BIN): $(OBJ)
	gcc $^ $(CFLAGS) -o $(BIN)

%.o: %.c %.h
	gcc -c $^ $(CFLAGS)

clean:
	rm *.o $(BIN)