
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
	string inputFile;
	string encodedFile = "";
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

	Node frequency = new Node[28];
	
	//initialize each char value in frequency to a-z and space
	for(int i=1; i<28; i++){
		if(i==27){
			frequency[i].setC(32); //32 is ascii value for space
		}
		else
			frequency[i].setC(i+97);
	}
	
	//update frequencies of chars in frequency by iterating through array
	
	string::iterator it = input.begin();
	//const char* cInput = input.c_str();
	for(int i=0; i<input.end(); i++){
		int x = (int)input[i] - 92;
		if(x < 0){
			frequencey[27].setFreq(frequencey[27].getFreq()+1);
		}
		frequencey[x].setFreq(frequencey[x].getFreq()+1);
	}

	try
	{
		//complete heap
		Heap h = new Heap(frequency, 28);
		
		//pass it over to HE
		HE var = new HE(h);
		var.invariant();
		var.fillE(holder, 0);
		var.setBits(var.getE());
		
	}
	catch(exception& ex)
	{
		cerr << ex.what() << endl;
	}
	return 0;
}

