CC = gcc
CFLAGS = -Wall
DEPS = tmp.h
OBJ = main.o tmp.o fun2.o
STD = -std=c++11
%.o: %.c $(DEPS)
	$(CC) -g $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	$(CC) $(CFLAGS) $(STD) -o $@ $^

debug: $(OBJ)
	$(CC) -g $(CFLAGS) $(STD) -o $@ $^

clean:
	rm *.o