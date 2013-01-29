//Andre Edwards
//Simple tests for doubly linked list structure
#include <iostream>
using namespace std;
#include "DLList.h"

int main() {

	DLList myList;

	myList.Append(8, 1);
	myList.Append(9, 2);
	myList.Append(76, 2);		//test for inserting between
	myList.Append(45, 12);		//test for inserting past the ending bounds of the list
	cout <<"\n\n";
	myList.PrintList();

	myList.Delete(76);
	myList.Delete(99);			//test for deleting non-existent data
	cout <<"\n\n";
	myList.PrintList();

	getchar();		//pause console to examine output
	return 0;
}