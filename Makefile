CXX=g++
CXXFLAGS=-std=c++11 -Wall 
BINARIES=heap




test:${BINARIES}
	./heap

heap: Heap.o Main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@




clean:
	/bin/rm -f ${BINARIES} *.o
