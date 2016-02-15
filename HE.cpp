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
	int asciiValue = r->getC() -96;
	if(asciiValue > 0 && asciiValue < 27){
	//	std::cout << r->getC() << " , " << r->getBit() << std::endl;
	//	Node* tmp = new Node(*r);
		this->encoded[asciiValue] = *r; 
	}
	if(asciiValue == -64){
	//	std::cout << r->getC() << " , " << r->getBit() << std::endl;
	//	Node* tmp = new Node(*r);
		this->encoded[27] = *r;
	}
}

std::string HE::encodedinput(std::string input){
	std::string encoded ="";
	for(int i =0; i < input.length(); i++){
		int asciiValue = input[i] - 96;
		if(asciiValue > 0 && asciiValue < 27)
			encoded = encoded + this->encoded[asciiValue].getBit();
		else if(asciiValue == -64)
			encoded = encoded + this->encoded[27].getBit();

	}
	return encoded;
}

std::string HE::bruteForce(std::string code){
		std::string returner = "";
		std::string temp = "";
		for(int i = 0; i < code.length(); i++){
			temp = temp + code[i];
			for(int j = 1; j < 28; j++){
				if(encoded[j].getFreq() > 0 && (encoded[j].getBit().compare(temp) == 0)) {
					returner+= encoded[j].getC();
					temp = "";
				}
			}
		}
		return returner;
	}

void HE::printEncoded(){
	for(int i=1; i<28; i++){
		std::cout << encoded[i].getC() << " , " << encoded[i].getBit() << std::endl;
	}
}



