#ifndef __HE_H__
#define __HE_H__

#include <string>
#include "Heap.h"

class HE{
	private:
		Heap h;
		Node* holder;
		
	public:
		
		HE(Heap input, int size);
		void setBits(Node* a);
		void insert(Node n);
		Node remove();
		//void fillE(Node* n, int i);
		//void invariant();
		Node* getHolder();
		void printNodes(Node* n);

};

#endif