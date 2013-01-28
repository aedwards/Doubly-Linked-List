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
	cout <<"\n\n";
	myList.PrintList();

	myList.Delete(82);
	cout <<"\n\n";
	myList.PrintList();

	getchar();
	return 0;
}