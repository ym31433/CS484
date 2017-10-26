RM := rm -rf

HEADERS = mp2-helper.h
OBJS = mp2-helper.o mp2.o

all: mp2

mp2: $(OBJS)
	@echo 'Building target: $@'
	mpicc -O2 -o "./mp2" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

%.o: %.c $(HEADERS)
	mpicc -O2 -c $< -o $@

xeon:
	icc -mmic -qopenmp mp2.c mp2-helper.c mp2-helper.h -o mp2.mic

clean:
	-$(RM) $(OBJS)
	-$(RM) ./mp2 ./mp2.mic
	-@echo ' '

.PHONY: all clean dependents directories
.SECONDARY:

