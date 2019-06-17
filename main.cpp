#include "DoublyLinkedList.h"
#include<stdlib.h>
#include <iostream>
using namespace std;

//What is doubly linked list?
	//its like a single linked list with a forwards a backwards pointer
//what are the advantages of using a doubly linked list?
	//you can access elements closer to the tail end of the program in half the time as normal linked lists

int main() {
	LinkedList *mylist = new LinkedList;

	mylist->insert(0, 1);
	mylist->insert(1, 2);
	mylist->insert(2, 3);
	mylist->insert(3, 4);
	mylist->insert(4, 5);
	mylist->print_reverse_List();
	


	system("pause");
	return 0;
}