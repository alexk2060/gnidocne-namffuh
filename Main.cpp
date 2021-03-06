
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



int main()
{
	char const* inputFile = "plain.input"; //plain text
	char const* encodedFile = "encoded.input"; //bits
	
	ifstream is;
	is.open(inputFile);
	string input = "";

	while(getline(is, input))
		;
	is.close(); //close input stream for plain.input


	Node frequency[28];
	//initialize each char value in frequency to a-z and space
	for(int i=1; i<28; i++){
		if(i==27){
			frequency[i].setC(32); //32 is ascii value for space
		}
		else
			frequency[i].setC(i+96);
	}
	
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

	//getting all non zero elements in array
	
	Node* nonZeroFrequencies = new Node[uniqueChars+1];
	int count = 1;
	for(int i=1; i<28; i++){
		if(frequency[i].getFreq() > 0){
			nonZeroFrequencies[count] = frequency[i];
			++count;
		}
	}

	Heap h(nonZeroFrequencies, uniqueChars);
	h.invariant();
	Node* root = &(h.getArr()[1]);
	h.assignBit("", root);
	HE he(h);

	string encodedPart = he.encodedinput(input);
	//cout << "encoded part: ";
	cout << encodedPart << endl;
//---------------------------------------------------------------------------
	//decoded part
	
	string encodedIn = "";
	is.open(encodedFile);
	while(getline(is, encodedIn))
		;
	is.close();

	string complete = he.bruteForce(encodedIn);
	//string complete = he.fasterImp(encodedIn);
	cout << complete << endl;
	
	return 0;
}

