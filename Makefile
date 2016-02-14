CXX=g++
CXXFLAGS=-Wall
			#-std=c++11
BINARIES=heap




test:${BINARIES}
	./prog2

prog2: Main.o HE.o Heap.o
	$(CXX) $(CXXFLAGS) $^ -o $@




clean:
	/bin/rm -f ${BINARIES} *.o