CXX=g++
CXXFLAGS=-Wall -g
			#-std=c++11
BINARIES=prog2




#test:${BINARIES}
#	./prog2

prog2: Main.o HE.o Heap.o
	$(CXX) $(CXXFLAGS) $^ -o $@




clean:
	/bin/rm -f ${BINARIES} *.o