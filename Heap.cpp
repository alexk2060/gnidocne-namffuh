#include "Heap.h"
#include <iostream>


template <class T>
Heap<T>::Heap(){
	numElements = 1; //initialize to one so our calculations are easier. Means that arr[1] is now the min. 
	ARR_SIZE = 32;
	arr = new T[ARR_SIZE]; 
}

template <class T>
int Heap<T>::getParent(const int &child) {
	return child/2;
}

template <class T>
int Heap<T>::getLeftChild(const int &parent) {
	return 2*parent;
}

template <class T>
int Heap<T>::getRightChild(const int &parent) {
	return 2*parent + 1;
}

template <class T>
void Heap<T>::insert(T const& v){
	if(numElements < ARR_SIZE){
		this->arr[numElements] = v;
		++(this->numElements);
		//percolate();
		std::cout<< "success" << std::endl;
	}
	else{
		std::cout << "No more space to insert items. Write code to resize heap \n";
	}
}

template <class T>
void Heap<T>::deleteMin(){
	this->arr[1] = this->arr[numElements];
	//percolate();
	
}


template <class T>
void Heap<T>::percolateDown(int location){
	T tmp = this->T[location];
	int child = location;
	for(location; 2*location <= numElements; location = child){
		child = 2*location;
		if(child != numElements && this->T[child+1] < this->T[child])
			++child;
		if(this->T[child] < this->T[location]){
			this->T[location] = this->T[child];
			this->T[child] = tmp;
		}
		else
			break;

	}

}

template <class T> 
void Heap<T>::buildHeap(T *arr, int size){

}



