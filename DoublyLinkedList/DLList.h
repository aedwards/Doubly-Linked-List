//Andre Edwards
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

	//append a node by data only
	void AppendNode(int data) {

		// Create a new node
		Node* newNode = new Node();
		newNode->SetData(data);
		newNode->SetNext(NULL);

		// Create a temp pointer
		Node *tmp = head;

		if ( tmp != NULL ) {
			// Nodes already present in the list
			// Parse to end of list
			while ( tmp->Next() != NULL ) {
				tmp = tmp->Next();
			}

			// Point the last node to the new node
			tmp->SetNext(newNode);
		}
		else {
			// First node in the list
			head = newNode;
		}
	}

	//append a node by data and position
	void Append(int data, int position) {

		int currentPosition = 1;
		Node *newNode;

		/* Decided to use an easier nomenclature in naming our tempNode (similar to Singular Linked List version) to currentNode.
		It eases the mental gymnastics when visualizing the traversal through the list when we want to keep track of our place
		when inserting or deleting nodes. The name positionNode is also a viable choice.*/
		Node *currentNode;

		newNode = new Node();		//new node that we'll be inserting

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
			if(position > currentPosition+1) {
				cout << "Invalid position." << endl;
				return;
			}
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
			currentNode->Next()->SetPrev(newNode);
			currentNode->SetNext(newNode);
		}
		
	}



	//Delete a node from the list based on the list item supplied by the user
	void Delete(int data) {

		Node *currentNode, *tempNode, *prevNode;	//initialize a pointer to the head node as a starting point

		currentNode = head;
		prevNode = NULL;

		//no nodes
		if(currentNode == NULL) {
			cout << "List is empty." << endl;
			return;
		}
		
		
		//trying to delete a non-existent node
		
		
		//deleting the head node
		if(currentNode->Data() == data) {
			prevNode = currentNode;
			currentNode = currentNode->Next();
			head = currentNode;		//point the head node to the next element in the list so that it does not get deleted
			if(currentNode != NULL) {
				currentNode->SetPrev(NULL);		//disassociate the first node from the list by having head node's prev pointer point to NULL.
			}
			
			delete prevNode;		//completely deallocate currentNode and assign a nullptr to avoid dangling pointers and memory leaks
			prevNode = nullptr;
			return;
		}
		else {

			//traverse through the nodes until we get a match (Intermediate node deletion)
			while(currentNode != NULL) {
				if(currentNode->Data() == data) {
					break;	
				}
				prevNode = currentNode;
				currentNode = currentNode->Next();
			}

			if(currentNode->Data() != data) {
				cout << "\n\n\nInvalid search: The item " << data << " does not exit.  Continuing remaing operations." << endl;
				return;
			}

			//adjust the pointers, if matching data is found
			prevNode->SetNext(currentNode->Next());
			currentNode->Next()->SetPrev(prevNode);

			//delete the current node
			delete currentNode;
		}

		
	}

	int ListLength() {
		Node *currentNode = head;
		int count = 0;

		while(currentNode != NULL) {
			count++;
			currentNode = currentNode->Next();
		}
		return count;
	}


	//Retrieve the head of a list.
	//Is only valid AFTER a list has been created.
	Node* Head() {

		if(head == NULL) {
			cout << "You must initialize a list with valid data before you can retrieve it's head.\nDoes NOT work on empty lists." << endl;
		}
		else {
			Node* newHead;
			newHead = head;
			return newHead;
		}
	}

	//Retrieve the head of a list.
	//Is only valid AFTER a list has been created.
	Node* Tail() {
		
		Node* tail = head;

		while(tail->Next() != NULL) {
			tail = tail->Next();
		}
		return tail;
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


	/*SwapNodes and ReverseList are a work in progress*/
	/*
	//Simple swap function
	void swapNodes(Node& headNode, Node& tailNode) {
		Node temp = headNode;
		headNode = tailNode;
		tailNode = temp;
	}
	
	//Reverse the list and return it
	void ReverseList(DLList list, Node* head, Node* tail) {

		
		cout << "Before swap: \n" << head->Data() << endl;
		cout << tail->Data() << endl;
		swapNodes(*head,*tail);
		cout << "After swap: \n" << head->Data() << endl;
		cout << tail->Data() << endl;
		
		cout << list.ListLength();
		
		
		
		//divide and conquer for loop
		for(int i = 0; i < list.ListLength()/2; i++) {
			
				swapNodes(*head, *tail);
				head->SetNext(head->Next());
				tail->SetNext(tail->Next());
				//emptyList.AppendNode(head->Data());
				//emptyList.AppendNode(tail->Data());
			
		}
		//return emptyList;

	}*/


};