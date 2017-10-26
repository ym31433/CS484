RM := rm -rf

HEADERS = gs-helper.h
OBJS = gs-helper.o gs.o

CC = gcc-5

all: gs

gs: $(OBJS)
	@echo 'Building target: $@'
	$(CC) -O2 -fopenmp -o "./gs" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

%.o: %.c $(HEADERS)
	$(CC) -O2 -fopenmp -c $< -o $@

xeon:
	icc -mmic -qopenmp gs.c gs-helper.c gs-helper.h -o gs.mic

clean:
	-$(RM) $(OBJS)
	-$(RM) ./gs ./gs.mic
	-@echo ' '

.PHONY: all clean dependents directories
.SECONDARY:
