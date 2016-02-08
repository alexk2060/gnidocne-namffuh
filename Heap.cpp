#include "Heap.h"
#include <iostream>



Heap::Heap(){
	numElements = 1; //initialize to one so our calculations are easier. Means that arr[1] is now the min. 
	size = 32;
	arr = new Node[size]; 
}

Heap::~Heap(){

}

Heap::Heap(Node *arr, int currentSize){
	this->numElements = currentSize;
	this->size = currentSize;
	this->arr = arr;
	for(int i = numElements; i > 0; i--)
		percolateDown(i);

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
		percolateUp(numElements);
		++(this->numElements);
		std::cout<< "success" << std::endl;
	}
	else{
		std::cout << "No more space to insert items. Write code to resize heap \n";
	}
}


Node Heap::deleteMin(){
	Node tmp = this->arr[1];
	this->arr[1] = this->arr[numElements];
	--(this->numElements);
	this->percolateDown(1);
	return tmp;
}



void Heap::percolateDown(int location){
	//std::cout << "perc called" << std::endl;
	Node tmp = this->arr[location];
	int child = location;
	for(location; 2*location <= numElements; location = child){
		//std::cout << "looped" << std::endl;
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
	std::cout << "perc called" << std::endl;
	Node tmp = this->arr[location];
	int parent = location;
	for(location; location/2 > 0; location = parent){
		std::cout << "looped" << std::endl;
		parent = this->getParent(location);
		std::cout << parent << std::endl;		
		std::cout << location << std::endl;

		if(this->arr[parent].getFreq() < this->arr[location].getFreq()){
			std::cout << "parent less than" << std::endl;
			this->arr[location] = this->arr[parent];
			this->arr[parent] = tmp; 
		}
		else
			break;
	}
}

//print out each array level 
void Heap::print(){
	for(int i = 1; i<this->numElements; i++)
		std::cout << i << ":	"<< this->arr[i].getC() << ", "<< this->arr[i].getFreq() << std::endl;
}





