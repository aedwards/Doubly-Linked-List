
//Node class for Doubly Linked List implementation.

class Node {


	
public:

	int data;
	Node* next;
	Node* prev;

	//default ctor
	Node() {
	}

	//setters
	void SetData(int aData) {
		data = aData;
	}

	void SetNext(Node* aNext) {
		next = aNext;
	}

	void SetPrev(Node* aPrev) {
		prev = aPrev;
	}


	//getters
	int Data() {
		return data;
	}

	Node* Next() {
		return next;
	}

	Node* Prev() {
		return prev;
	}


};