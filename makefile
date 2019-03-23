CC = gcc
CFLAGS = -Wall
DEPS = tmp.h
OBJ = main.o tmp.o fun2.o
STD = -std=c++11
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	gcc $(CFLAGS) $(STD) -o $@ $^
