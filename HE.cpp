#include <iostream>

using namespace std;

	HE::HE(Heap input){
		h = input;
		holder = NULL;
		e = new encode[28];
	//	size = 28;
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

	void HE::insert(Node n){
		if (holder == NULL){
			holder = &n;
			return;
		}
		else{
			//whatever was first goes left and the second one goes right
			Node* internal = new Node('!');
			int newNumber = n.getFreq() + holder->getFreq();
			internal->setFreq(newNumber);
			internal->setLeft(holder);
			internal->setRight(&n);
			holder = internal;
		}
	}

	Node HE::remove(){
		Node* t = holder;
		holder = NULL;
		return *(t);
	}

	void HE::fillE(Node* n, int i){
		if(n == NULL)
			return;
		encode *tmp = new encode(n);
		e[i] = *tmp;
		fillE(n->getLeft(),i*2);
		fillE(n->getRight(),(i*2+1));
	}

	void HE::invariant(){
		while(h.getNumElements()!=1){
			insert(h.deleteMin());
			insert(h.deleteMin());
			Node t = remove();
			h.insert(t);
			if(h.getNumElements() == 1)
				holder = &t;
		}
	}

	HE::encode* HE::getE(){
		return e;
	}

	Node* HE::getHolder(){
		return holder;
	}