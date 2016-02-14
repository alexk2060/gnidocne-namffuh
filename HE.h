#ifndef __HE_H__
#define __HE_H__

#include <string>
#include "Heap.h"

class HE{
	private:
		struct encode{
			encode(){
				n= new Node();
				bit = "";
			}
			encode(Node* input):n(input){};
			Node* n;
			std::string bit;
		};
		Heap h;
		encode* e;
		//int size;
		Node* holder;

		
	public:
		
		HE(Heap input, int size);
		void setBits(encode* a);
		void insert(Node n);
		Node remove();
		void fillE(Node* n, int i);
		void invariant();
		encode* getE();
		Node* getHolder();
		void printNodes(Node* n);

};

#endif