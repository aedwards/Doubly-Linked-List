//Andre Edwards
//Simple tests for doubly linked list structure
#include <iostream>
using namespace std;
#include "DLList.h"

int main() {

	DLList myList;

	
	myList.Append(8, 1);
	myList.Append(9, 2);
	myList.Append(34,3);
	myList.Append(76, 2);		//test for inserting between
	myList.Append(45, 12);		//test for inserting past the ending bounds of the list
	myList.Append(112, 3);
	
	cout <<"\n\n";
	myList.PrintList();

	myList.DeleteNode(2);			
	cout <<"\n\n";
	myList.PrintList();

	cout <<"\n\n";
	int listCount = myList.ListLength();
	cout << "Total list count: " << listCount << endl;
	myList.PrintList();


	//retrieves the head & tail of the list.  Can only be used AFTER a list has been created.
	/*Also, the variable that stores the value returned by the Head() function must be a pointer to a Node because that
	is the type returned by the Head() function.*/
	Node* myTail = myList.Tail();
	Node* myHead = myList.Head();
	cout << "\n\n\n" << "Head of List: " << myHead->Data() << "\n" << endl;
	cout << "\n" << "Tail of List: " << myTail->Data() << "\n\n\n" << endl;
	
	
	

	getchar();		//pause console to examine output
	return 0;
}