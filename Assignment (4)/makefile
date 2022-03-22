CC=g++

CFLAGS=-Wall -c

seq_ex3: node1.o sequence3.o seq_ex3.o
	$(CC) node1.o sequence3.o seq_ex3.o
	
sequence_test: node1.o sequence3.o sequence_test.o
	$(CC) node1.o sequence3.o sequence_test.o
	
node1.o: node1.cpp
	$(CC) $(CFLAGS) node1.cpp
	
sequence3.o: sequence3.cpp
	$(CC) $(CFLAGS) sequence3.cpp
	
sequence_test.o: sequence_test.cpp
	$(CC) $(CFLAGS) sequence_test.cpp
	
seq_ex3.o: seq_ex3.cpp
	$(CC) $(CFLAGS) seq_ex3.cpp
	
clean:
	rm -rf *o exam test
