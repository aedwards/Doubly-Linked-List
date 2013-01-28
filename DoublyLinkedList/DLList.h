//custom List class
#include <iostream>
using namespace std;
#include "Node.h"

class DLList { 


	Node *head;
	Node *prev;

public:
	
	DLList() {

		head = NULL;	//initialize the default head position
	}

	
	void Append(int data, int position) {

		int currentPosition = 1;
		Node *newNode;

		/* Decided to use an easier nomenclature in naming our tempNode (similar to Singular Linked List version) to currentNode.
		It eases the mental gymnastics when visualizing the traversal through the list when we want to keep track of our place
		when inserting or deleting nodes. The name positionNode is also a viable choice.*/
		Node *currentNode;

		newNode = new Node();		//out brand new node that we'll be inserting

		//Do not allow insertion if the the position is less than 0
		if(position < 0) {
			cout << "Cannot enter " << data << " into list." << endl;
			cout << "Please enter a position larger than or equal to 0." << endl;
			return;
		}

		//Exit immediately if node is invalid.
		if(!newNode) {
			cout << "Memory Error while allocating" << endl;
			return;
		}

		newNode->SetData(data);
		//when node is entered as the first element
		if(position == 1) {
			cout << "Inserting node at the beginning of the list." << endl;
			newNode->SetNext(head);
			newNode->SetPrev(NULL);
			head = newNode;
			return;
		}

		/*The following logic decides if the element is inserted at the end of the list
		or at the specified position.*/
		currentNode = head;		//initialize
		while((currentPosition < position - 1) && (currentNode->Next() != NULL)) {
			currentNode = currentNode->Next();
			currentPosition++;
		}

		if(currentNode->Next() == NULL) {
			cout << "Inserting node at the last." << endl;
			newNode->SetNext(currentNode->Next());	//newNode's next pointer is set to NULL; as any end node's next pointer should be.
			newNode->SetPrev(currentNode);			//newNode's previous pointer points to the currentNode we inserted AFTER, at the end of the list.
			currentNode->SetNext(newNode);			//because newNode now comes after currentNode, we have to set currentNode's next pointer to point to newNode.
		}
		else {
			//insertion at user specified place
			/* Understanding this is very simple.  Just visualize a number list, for example 1,2,3,4,5; pick a 'position' and just 
			imagine left or right arrows pointing to the appropriate nodes based on the next and previous pointer assignments below.*/
			cout << "Inserting node at position: " << position << endl;
			newNode->SetNext(currentNode->Next());
			newNode->SetPrev(currentNode);
			currentNode->next->prev = newNode;
			currentNode->SetNext(newNode);
			return;
		}
		
	}


	void PrintList() {
		Node *currentNode = head;

		if(currentNode == NULL) {
			cout << "List is empty";
			return;
		}
		
		while(currentNode->Next() != NULL) {
			cout << currentNode->Data();
			cout << "<==>";
			currentNode = currentNode->Next();
		}

		cout << currentNode->Data();
		return;
	}



	


};