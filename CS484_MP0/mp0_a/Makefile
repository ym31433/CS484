CC=g++
CCFLAGS = -O3

all: mp0_a

mp0_a: mp0_a.o
	$(CC) $(CCFLAGS) mp0_a.o -o mp0_a

mp0_a.o:
	$(CC) $(CCFLAGS) -c mp0_a.c

clean:
	rm -f *.o mp0_a
