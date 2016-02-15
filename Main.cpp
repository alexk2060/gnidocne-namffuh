
#include <iostream>
#include <fstream>
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
	ifstream is;
	is.open(inputFile);
	string input = "";
	while(getline(is, input));
	cout << input << endl;
	is.close();
	//input = "i like apples";


	Node frequency[28];
	//initialize each char value in frequency to a-z and space
	for(int i=1; i<28; i++){
		if(i==27){
			frequency[i].setC(32); //32 is ascii value for space
		}
		else
			frequency[i].setC(i+96);
	}
	//-----------------------------------------
	cout << "\n";

	//update frequencies of chars in frequency by iterating through array
	int uniqueChars = 0;
	for(int i=0; i < input.length(); i++){
		int x = input[i] - 96;

		if(x > 0 && frequency[x].getFreq() == 0)
			uniqueChars++;
		if(x < 0 && frequency[27].getFreq() == 0)
			uniqueChars++;

		if(x > 0)
			frequency[x].setFreq(frequency[x].getFreq() + 1);
		else
			frequency[27].setFreq(frequency[27].getFreq() + 1);
	
	}	
	//------------------------------------------
	//getting all non zero elements in array
	Node* nonZeroFrequencies = new Node[uniqueChars+1];
	int count = 1;
	cout << "# of chars " << uniqueChars << "\n";
	for(int i=1; i<28; i++){
		if(frequency[i].getFreq() > 0){
			nonZeroFrequencies[count] = frequency[i];
			++count;
		}
	}


	for(int i = 0; i < uniqueChars+1; i++){
		cout << i << " " << nonZeroFrequencies[i].getC() << endl;
	}


	cout << "and uniquechars is " << uniqueChars << endl;

		Heap h(nonZeroFrequencies, uniqueChars);
		cout << "Heap successfully built" << endl;
		h.print();
		h.invariant();
		h.print();
		Node* root = &(h.getArr()[1]);
		h.assignBit("", root);
		//h.printTree(root);		
		HE he(h);

		string encodedPart = he.encodedinput(input);
		cout << "encoded part: " << encodedPart << endl;
	is.close();
	return 0;
}

