
//Node class for Doubly Linked List implementation.

//Andre Edwards
//Custom Node Class for Doubly Linked lists
class Node {

private:
	int data;
	Node* next;
	Node* prev;
	
public:

	

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