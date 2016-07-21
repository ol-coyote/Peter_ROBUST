# Author: Pedro Estrada                                                           
# Email:  pestrada2@miners.utep.edu                                               

CC=gcc
OBJ_S=sinTest 
DEPS=sinTest.h utility.h
S_SRC=sinTest.c utility.c
#CC=gcc
#OBJ_S=pitest
#DEPS=sinTest.h
#S_SRC=pitest.c

OBJ=-o
MATH=-lm

all: $(OBJ_S)
#$(OBJ_S): $(S_SRC)
#	$(CC) $(OBJ) $(OBJ_S) $(S_SRC) $(MATH)

$(OBJ_S): $(S_SRC) $(DEPS)
	$(CC) $(OBJ) $(OBJ_S) $(S_SRC) $(MATH)
clean:
	rm *.o; rm *.o~; rm *~; rm $(OBJ_C); rm $(OBJ_S);
