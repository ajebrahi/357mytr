CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
MAIN = mytr
OBJS = mytr.o
all : $(MAIN)

$(MAIN): $(OBJS) mytr.c
	$(CC) $(CFLAGS) $(OBJS) -o $(MAIN)

mytr.o: mytr.c
	$(CC) $(CFLAGS) -c mytr.c
clean:
	rm *.o $(MAIN) core                                     
