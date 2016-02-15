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
			bit = "";
			left = NULL;
			right = NULL;
		}
		Node(char a){
			c=a;
			freq=0;
			bit = "";
			left = NULL;
			right = NULL;
		}
		Node &operator=(Node const &rhs){
			this->c = rhs.getC();
			this->freq = rhs.getFreq();
			this->bit = rhs.getBit();
			this->left = rhs.getLeft();
			this->right = rhs.getRight();
			return *this;

		}
		void setC(char character){c=character;};
		void setFreq(int f){freq = f;};
		void setBit(std::string s){bit = s;};
		void setLeft(Node* n){this->left = n;};
		void setRight(Node* n){this->right = n;};
		char getC() const {return c;};
		int getFreq() const {return freq;};
		std::string getBit() const {return bit;};
		Node* getLeft() const {return left;};
		Node* getRight() const {return right;};		
};

#endif