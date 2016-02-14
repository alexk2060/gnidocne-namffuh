#include "HE.h"
#include <iostream>

using namespace std;

	HE::HE(Heap input, int size){
		h = input;
		holder = NULL;
	}
	
	void HE::setBits(Node* a){
		for(int i = 1; i < 28; i++){
			if(i==1)
				a[1].setBit("");
			if(i==2)
				a[2].setBit("1");
			if(i==3)
				a[3].setBit("0");
			else{
				if(i%2==0)
					a[i].setBit(a[i/2].getBit() + "1");
				else
					a[i].setBit(a[i/2].getBit() + "0");
			}
		}
	}

	Node HE::remove(){
		Node* t = holder;
		holder = NULL;
		return *(t);
	}
	/*
	void HE::fillE(Node* n, int i){
		if(n == NULL)
			return;//
		if(n->getLeft() == NULL && n->getRight()== NULL){
			encode tmp(n);
			for(int j = 0; j< 28; j++){
				if(e[j].n->getC()=='\0'){
					e[j] = tmp;
					break;
				}
			}
		}
		fillE(n->getLeft(),i*2);
		fillE(n->getRight(),(i*2+1));
		return;
	}
	*/

	void HE::insert(Node n){
		if (holder == NULL){
			holder = &n;
			//right node child
			return;
		}
		else{
			//whatever was first goes left and the second one goes right
			Node* internal = new Node('!');
			int newNumber = n.getFreq() + holder->getFreq();
			internal->setFreq(newNumber);
			internal->setRight(holder);
			internal->setLeft(&n);
			holder = internal;
			cout << internal->getFreq() << " " << internal->getC() << endl;
			cout << internal->getLeft()->getFreq() << " "  << internal->getLeft()->getC() << endl;
			cout << internal->getRight()->getFreq() << " "  << internal->getRight()->getC() << endl;
		}
	}
	
	Node* HE::getHolder(){
		return holder;
	}

	void HE::printNodes(Node* n){
		if(n==NULL)
			return;
		cout << n->getFreq() << " " << n->getC() << endl;
		printNodes(n->getLeft());
		printNodes(n->getRight());
		return;
	}