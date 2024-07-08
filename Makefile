# define compiler
CC=gcc
# list of flags (options) to pass to the compiler 
CFLAGS= -lncurses -Wall -Wextra -pedantic -std=c17
# all object files compiled
OBJ = main.o

# -o $@ puts the compiled file on the left of : (though i don't know its use)
# $< is the first item in the dependencies list

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

output: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o output