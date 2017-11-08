CHARMC = /scratch/users/donghun2/charm-v6.8.2/bin/charmc $(OPTS)
TESTOPTS = ++local

OBJS = particle.o

ITER = 20
MULT = 2
CHARES = 4

all: particle

particle: $(OBJS)
	$(CHARMC) -O3 -language charm++ -module CommonLBs -o particle $(OBJS)

particle.decl.h: particle.ci
	$(CHARMC)  particle.ci

clean:
	rm -f *.decl.h *.def.h conv-host *.o particle charmrun

cleanp:
	rm -f *.sts *.gz *.projrc *.topo *.out

particle.o: particle.C particle.decl.h
	$(CHARMC) -c particle.C #-DUSE_LB

test: all
	./charmrun particle +p4 $(ITER) $(MULT) $(CHARES) $(TESTOPTS)

test_balancer: all
	./charmrun particle +p2 $(ITER) $(MULT) $(CHARES) $(TESTOPTS) +balancer RefineLB
