#include "HE.h"
#include <iostream>
#include <string>

HE::HE(Heap h){
	root = &(h.getArr()[1]);
	encoded = new Node[28];
	for(int i=1; i<28; i++){
		if(i==27){
			encoded[i].setC(32); //32 is ascii value for space
		}
		else
			encoded[i].setC(i+96);
	}
	this->buildEncoded(this->root);
}


void HE::buildEncoded(Node* r){
	if(r == NULL)
		return;
	buildEncoded(r->getLeft());
	buildEncoded(r->getRight());
	int asciiValue = r->getC() - 96;
	if(asciiValue > 96 && asciiValue < 123)
		this->encoded[asciiValue] = *r; 
	if(asciiValue == -62)
		this->encoded[27] = *r;
}

std::string HE::encodedinput(std::string input){
	std::string encoded ="";
	for(int i =0; i < input.length(); i++){
		int asciiValue = input[i] - 96;
		if(asciiValue > 96 && asciiValue < 123)
			encoded = encoded + this->encoded[asciiValue].getBit();
		else if(asciiValue == -62)
			encoded = encoded + this->encoded[27].getBit();

	}
	return encoded;
}

std::string findEncodedBits(char c, Node* r){
	if(r == NULL)
		return "";
	
	findEncodedBits(c, r->getLeft());
	findEncodedBits(c, r->getRight());

	if(r->getC() == c)
		return r->getBit();
}

std::string HE::decodedOutput(std::string encodedinput){
	std::string decoded = "";
	for(int i = 0; i<encodedinput.length(); i++)
		decoded = decoded + findEncodedBits(encodedinput[i], this->root);

}



