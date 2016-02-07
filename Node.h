#ifndef __NODE_H__
#define __NODE_H__

#include <string.h>

class Node{

	private:
		char c;
		int freq;
		Node* left;
		Node* right;

	public:
		char getC(){return c;};
		int getFreq(){return freq;};
		Node* getLeft(){return left;};
		Node* getRight(){return right;};
		
}