CC=g++
CCFLAGS = -O3

all: mp0_b

mp0_b: mp0_b.o test1.o test2.o test3.o test4.o test5.o util.o timers.o
	$(CC) $(CCFLAGS) mp0_b.o test1.o test2.o test3.o test4.o test5.o util.o timers.o -o mp0_b

mp0_b.o:
	$(CC) $(CCFLAGS) -c mp0_b.c

test1.o:
	$(CC) $(CCFLAGS) -c test1.c

test2.o:
	$(CC) $(CCFLAGS) -c test2.c

test3.o:
	$(CC) $(CCFLAGS) -c test3.c

test4.o:
	$(CC) $(CCFLAGS) -c test4.c

test5.o:
	$(CC) $(CCFLAGS) -c test5.c

util.o:
	$(CC) $(CCFLAGS) -c util.c

timers.o:
	$(CC) $(CCFLAGS) -c timers.c

clean:
	rm -f *.o mp0_b

