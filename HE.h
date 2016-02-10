#ifndef __HE_H__
#define __HE_H__

#include <string.h>
#include "Heap.h"

class HE{
	private:

		Heap h;
		encode[28] e;
		Node* holder;
		struct encode{
			encode(Node input):n(input){};
			Node n;
			std::String bit;
		};
		
	public:
		
		HE(Heap input);
		void setBits();
		void insert(Node n);
		Node remove();
		void fillE(Node* n, int i);
		void invariant();
		encode* getE();

};

#endif