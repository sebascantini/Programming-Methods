CC=g++

NAME=tp1

_DEPS = headers.h dinamicPrograming.h bruteForce.h backtracking.h
DEPS = $(_DEPS)

_OBJ = main.o dinamicPrograming.o bruteForce.o backtracking.o
OBJ = $(_OBJ)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(NAME) *.o *~ core $(INCDIR)/*~