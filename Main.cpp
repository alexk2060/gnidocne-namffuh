
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include <cstring>


#include "Node.h"
#include "Heap.h"
#include "HE.h"

using namespace std;



int main(int argc,char *argv[])
{
	char const* inputFile;
	char const* encodedFile = "";
	if(argc < 2){
		inputFile = "plain.input";
		encodedFile = "encoded.input";
	}
	else if(argc == 2){
		inputFile = argv[2];
	}
	else{
		inputFile = argv[2];
		encodedFile = argv[3];
	}
	
	freopen(inputFile,"r",stdin);     // if you use this line, it merely redirects stdin to input.txt file; simple as that
	string input = "";
	cin >> input;
	input = "i like apples";

	Node frequency[28];
	//initialize each char value in frequency to a-z and space
	for(int i=1; i<28; i++){
		if(i==27){
			frequency[i].setC(32); //32 is ascii value for space
		}
		else
			frequency[i].setC(i+97);
	}
	
	//-----------------------------------------
	//update frequencies of chars in frequency by iterating through array
	int uniqueChars = 0;
	const char* cInput = input.c_str();
	for(int i=0; cInput[i] != '\0'; i++){
		int x = (int)input[i] - 92;
		if(frequency[x].getFreq() == 0)
			++uniqueChars;
		if(x < 0){
			frequency[27].setFreq(frequency[27].getFreq()+1);
		}
		frequency[x].setFreq(frequency[x].getFreq()+1);
	}
	//-----------------------------------------

	//getting all non zero elements in array
	Node* nonZeroFrequencies = new Node[uniqueChars];
	int count = 0;
	for(int i=0; i<28; i++){
		if(frequency[i].getFreq() > 0){
			nonZeroFrequencies[count] = frequency[i];
			++count;
		}
	}
	
	try
	{
		//complete heap
		Heap h(nonZeroFrequencies, uniqueChars);

		//pass it over to HE
		HE var(h);
		var.invariant();
		var.fillE(var.getHolder(), 1);
		var.setBits(var.getE());
		string output ="";
		for(int i = 0; cInput[i] != '\0'; i++){
			for(int j = 0; j < 27; j++){
				if(var.getE()[j].n->getC()==input[i])
					output += var.getE()[j].n->getC();
			}
		}
		cout<< "print encoded string" << endl;
		cout << output;
	}
	catch(exception& ex)
	{
		cerr << ex.what() << endl;
	}
	delete[] nonZeroFrequencies;
	return 0;
}