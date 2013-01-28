#include <iostream>
using namespace std;
#include "DLList.h"

int main() {

	DLList myList;

	myList.Append(8, 1);
	myList.Append(9, 2);
	myList.Append(76, 2);		//test for inserting between

	myList.PrintList();

	getchar();
	return 0;
}