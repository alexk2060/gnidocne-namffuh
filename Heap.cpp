#include "Heap.h"
#include <iostream>



Heap::Heap(){
	numElements = 1; //initialize to one so our calculations are easier. Means that arr[1] is now the min. 
	size = 32;
	arr = new Node[size]; 
}


int Heap::getParent(const int &child) {
	return child/2;
}


int Heap::getLeftChild(const int &parent) {
	return 2*parent;
}


int Heap::getRightChild(const int &parent) {
	return 2*parent + 1;
}


void Heap::insert(Node const& n){
	if(numElements < size){
		this->arr[numElements] = n;
		++(this->numElements);
		//percolate();
		std::cout<< "success" << std::endl;
	}
	else{
		std::cout << "No more space to insert items. Write code to resize heap \n";
	}
}


void Heap::deleteMin(){
	this->arr[1] = this->arr[numElements];
	//percolate();
	
}



void Heap::percolateDown(int location){
	Node tmp = this->arr[location];
	int child = location;
	for(location; 2*location <= numElements; location = child){
		child = this->getLeftChild(location);
		if(child != numElements && this->arr[child+1].getFreq() < this->arr[child].getFreq())
			++child;
		if(this->arr[child].getFreq() < this->arr[location].getFreq()){
			this->arr[location] = this->arr[child];
			this->arr[child] = tmp;
		}
		else
			break;

	}

}


void Heap::percolateUp(int location){
	Node tmp = this->arr[location];
	int parent = location;
	for(location; 2/location > 0; location = parent){
		parent = this->getParent(location);
	}
}

/* 
void Heap::buildHeap(T *arr, int currentSize){

}*/



