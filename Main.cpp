
#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>

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

	Node[] frequency = new Node[27];
	
	//initialize each char value in frequency to a-z and space
	for(int i=1; i<27; i++){
		if(i==0){
			frequency[i].setC(32); //32 is ascii value for space
		}
		else
			frequency[i].setC(i+97);
	}
	
	//update frequencies of chars in frequency by iterating through array
	string::iterator it = input.begin();
	//const char* cInput = input.c_str();
	for(int i=0; i<it.end(); i++){
		int x = (int)input[i] - 92;
		if(x < 0){
			frequency[0].setFreq(frequency[0].getFreq()+1);
		}
		frequency[x].setFreq(frequency[x].getFreq()+1);
	}
	
	//getting all non zero elements in array
	vector<Node> allFrequencies;
	for(int i=0; i<frequency.length; i++){
		if(frequency[i].getFreq() > 0){
			allFrequencies.push_back(frequency[i]);
		}
	}
	
	//moving elements from vector to array
	Node[] newFrequencies = new Node[allFrequencies.size()];
	for(int i=0; i<allFrequencies.size; i++){
		newFrequencies[i] = allFrequencies.at(i);
	}
	
	try
	{
		//complete heap
		Heap h = new Heap(newFrequencies, allFrequencies.size());
		
		//pass it over to HE
		HE var = new HE(h);
		var.invariant();
		var.fillE(holder, 0);
		var.setBits(var.getE());
		string output ="";
		for(int i = 0; i<it.end(); i++){
			for(int j = 0; j < 27; j++){
				if(var.getE()[j].n.getC()==input[i])
					output += var.getE().[j].n.getC();
			}
		}
		cout << output;
	}
	catch(exception& ex)
	{
		cerr << ex.what() << endl;
	}
	return 0;
}

