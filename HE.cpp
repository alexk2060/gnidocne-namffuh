#include "HE.h"
#include <iostream>

using namespace std;

	HE::HE(Heap input, int size){
		h = input;
		holder = NULL;
		e = new encode[size];
	}
	
	void HE::setBits(encode* a){
		for(int i = 1; i < 28; i++){
			if(i==1)
				a[1].bit="";
			if(i==2)
				a[2].bit = "1";
			if(i==3)
				a[3].bit = "0";
			else{
				if(i%2==0)
					a[i].bit = a[i/2].bit + "1";
				else
					a[i].bit = a[i/2].bit + "0";
			}
		}
	}

	Node HE::remove(){
		Node* t = holder;
		holder = NULL;
		return *(t);
	}

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


	void HE::invariant(){
		while(h.getNumElements()>1){
			h.print();
			Node right = h.deleteMin();
			Node left = h.deleteMin();
			cout << "right one is " << right.getC() << " " << left.getC() << endl;
			h.print();
 			cout << "\n";
			Node* internal = new Node('!');
			internal->setFreq(right.getFreq()+left.getFreq());
			internal->setRight(&right);
			internal->setLeft(&left);
			h.insert(*internal);
 			/*
			if(h.getNumElements() == 1){
				holder = &t;
			}*/
		}
	}

	HE::encode* HE::getE(){
		return e;
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