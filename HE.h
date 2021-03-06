#ifndef __HE_H__
#define __HE_H__

#include <string>
#include "Heap.h"

class HE{
	private:
		Node* root; //pointer to Trie in space 1 of Heap
		Node* encoded; //array with encoded bits. always 28
		void buildEncoded(Node*);

	public:
		HE(Heap h); //should only have one element which is the start of the trie
		std::string encodedinput(std::string input);
		//std::string decodedOutput(std::string encodedinput);
		//std::string findEncodedBits(std::string s, Node* r);
		void printEncoded();
		std::string bruteForce(std::string code);
		std::string fasterImp(std::string code);
};

#endif