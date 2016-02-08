#ifndef __Heap_H__
#define __Heap_H__


#include "Node.h"
class Heap{

private:
	
	int size;
	Node *arr;
	int numElements;

public:
	Heap();
	Heap(Node *arr, int currentSize); //build a heap from a given array.	
	~Heap();
	int getParent(const int &child);
	int getLeftChild(const int &parent);
	int getRightChild(const int &parent);
	
	//void minHeapify(int *a, int i, int size); //min Heap, so first element in array will be the smallest #
	
	void insert(Node const&);
	void print();
	Node deleteMin(); 


	void percolateDown(int location);
	void percolateUp(int location);

	int getSize(){return this->size;}
	int getNumElements(){return this->numElements;}
	Node* getArr(){return this->arr;}

};

#endif 