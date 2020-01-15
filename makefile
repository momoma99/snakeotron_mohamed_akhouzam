CFLAGS = -std=c99
SOURCES_LIB = clientAPI.c main.c snakeAPI.c deplace.c
OBJ_LIB=$(SOURCES_LIB:.c=.o)

%.o:%.c
	gcc $(CFLAGS) -c $<

execut: $(OBJ_LIB)
	gcc $(CFLAGS) $(OBJ_LIB) -o $@

clean:
	rm -f $(OBJ) execut
