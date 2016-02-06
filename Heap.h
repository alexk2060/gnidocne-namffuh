#ifndef __Heap_H__
#define __Heap_H__

template <class T>
class Heap{

private:
	
	int ARR_SIZE;
	T *arr;
	int numElements;

public:
	Heap();
	~Heap();
	Heap(T *arr, int currentSize); //build a heap from a given array.

	int getParent(const int &child);
	int getLeftChild(const int &parent);
	int getRightChild(const int &parent);
	
	//void minHeapify(int *a, int i, int size); //min Heap, so first element in array will be the smallest #
	
	void insert(T const&);
	void print();
	void deleteMin(); 

	void buildHeap(T *arr, int size); //requires an array input

	void percolateDown(int location);




};

#endif 