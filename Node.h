#ifndef __NODE_H__
#define __NODE_H__

#include <string>
class Node{

	private:
		char c;
		int freq;
		std::string bit;
		Node* left;
		Node* right;

	public:
		Node(){
			c='\0';
			freq = 0;
			left = NULL;
			right = NULL;
		}
		Node(char a){
			c=a;
			freq=0;
			left = NULL;
			right = NULL;
		};
		void setC(char character){c=character;};
		void setFreq(int f){freq = f;};
		void setBit(std::string s){bit = s;};
		void setLeft(Node* n){this->left = n;};
		void setRight(Node* n){this->right = n;};
		char getC(){return c;};
		int getFreq(){return freq;};
		std::string getBit(){return bit;};
		Node* getLeft(){return left;};
		Node* getRight(){return right;};		
};

#endif