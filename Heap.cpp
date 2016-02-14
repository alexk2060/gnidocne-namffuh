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
		++(this->numElements);
		this->arr[numElements] = n;
		percolateUp(numElements);
	}
	else{
		std::cout << "No more space to insert items. Write code to resize heap \n";
	}
}


Node Heap::deleteMin(){
	Node tmp = this->arr[1];
	this->arr[1] = this->arr[numElements];
	this->numElements = this->numElements - 1;
	this->percolateDown(1);
	return tmp;
}



void Heap::percolateDown(int location){
	Node tmp = this->arr[location];
	int child = location;
	for(; 2*location <= numElements; location = child){
		child = this->getLeftChild(location);
		if(child != numElements && this->arr[child+1].getFreq() == this->arr[child].getFreq())
			++child;
		else if(child != numElements && this->arr[child+1].getFreq() < this->arr[child].getFreq())
			++child;
		if(this->arr[child].getFreq() < this->arr[location].getFreq()){
			this->arr[location] = this->arr[child];
			this->arr[child] = tmp;
		}
		else
			break;
	}

}

	// Testing with cout:	std::cout << "perc called" << std::endl;
void Heap::percolateUp(int location){
	Node tmp = this->arr[location];
	int parent = location;
	for(; location/2 > 0; location = parent){
		parent = this->getParent(location);
		if(this->arr[location].getFreq() < this->arr[parent].getFreq() ){
			this->arr[location] = this->arr[parent];
			this->arr[parent] = tmp; 
		}
		else
			break;
	}
}

//print out each array level 
void Heap::print(){
	for(int i = 1; i<=numElements; i++)
		std::cout << i << ":	"<< this->arr[i].getC() << ", "<< this->arr[i].getFreq() << ", " << this->arr[i].getBit() << std::endl;
}

	void Heap::invariant(){
		while(getNumElements()>1){
			std::cout << "before: " << numElements << std::endl;			
			Node right = deleteMin();
			Node left = deleteMin();
			std::cout << "right one is " << right.getC() << " " << left.getC() << std::endl;
 			std::cout << "\n";
			Node* internal = new Node('!');
			internal->setFreq(right.getFreq()+left.getFreq());
			internal->setRight(&right);
			internal->setLeft(&left);
			std::cout << "after two deletes: " << numElements << std::endl;
			print();
			insert(*internal);
			std::cout << "after two deletes and one insert: " << numElements << std::endl;
			print();			/*
			if(getNumElements() == 1){
				holder = &t;
			}
			*/
		}
	}
	void Heap::assignBits(Node* arr, int size){
		arr[1].setBit("");
		arr[2].setBit("1");
		arr[3].setBit("2");
		for(int i = 4; i<size; i++){
			if(i%2==0)
				arr[i].setBit(arr[i/2].getBit()+"1");
			else
				arr[i].setBit(arr[i/2].getBit()+"0");
		}
	}

	void Heap::formArray(Node*arr, Node* root, int index){
		if(root == NULL)
			return;
		arr[index] = *root;
		formArray(arr, root->getLeft(), index*2);
		formArray(arr, root->getRight(), index*2+1);
	}

	int Heap::totalNodes(Node* a){
		if(a==NULL)
			return 0;
		else{
			return 1+totalNodes(a->getLeft()) + totalNodes(a->getRight());
		}
	}