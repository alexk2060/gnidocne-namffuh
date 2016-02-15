#ifndef __HE_H__
#define __HE_H__

#include <string>
#include "Heap.h"

class HE{
	private:
		Node* root; //pointer to Trie in space 1 of Heap
		Node* encoded; //array with encoded bits. always 28
		void buildEncoded();

	public:
		HE(Heap h); //should only have one element which is the start of the trie
		string encodedinput(string input);
		string decodedOutput(string encodedinput);


};

#endif