CXX=g++
CXXFLAGS=-std=c++11 -Wall 
BINARIES=heap HE




test:${BINARIES}
	./heap

heap: Heap.o HE.o Main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@




clean:
	/bin/rm -f ${BINARIES} *.o
