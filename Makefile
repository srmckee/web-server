#Makefile

PRE = g++ -Wall -g -std=c++11

ex16: ex16.o network.o
	$(PRE) -o $@ $^

ex16.o: ex16.cc
	$(PRE) -c $<

network.o: network.cc network.h
	$(PRE) -c $<

clean:
	rm -f *.o *~
