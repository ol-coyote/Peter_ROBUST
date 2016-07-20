# Author: Pedro Estrada                                                         
# Email:  pestrada2@miners.utep.edu                                               

CC=gcc
OBJ_S=main
DEPS= utility.h interpolObj.h calculate.h
S_SRC=main.c utility.c calculate.c

OBJ=-o
MATH=-lm

all: $(OBJ_S)
#$(OBJ_S): $(S_SRC)
#	$(CC) $(OBJ) $(OBJ_S) $(S_SRC) $(MATH)

$(OBJ_S): $(S_SRC) $(DEPS)
	$(CC) $(OBJ) $(OBJ_S) $(S_SRC) $(MATH)
clean:
	rm *.o; rm *.o~; rm *~; rm $(OBJ_C); rm $(OBJ_S);
