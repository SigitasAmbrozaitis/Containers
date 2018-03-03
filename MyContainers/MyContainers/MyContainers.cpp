// MyContainers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyStack.h"
#include "MyLinkedList.h"
#include "MyList.h"
#include "MyTree.h"

int main()
{
	//Stack
	//push works as intended
	//pop works as intended
	//scales more than 10000000, should go to infinity, aborted due to long test times
	
	//LinkedList
	// add all methods works as intended
	// del all methods works as intended
	// find all methods works as intended
	// more than 100000 elements scales without memory leaks

	//List 
	//add all methods works as intended
	//del all methods works as intended
	//find all methods works as intended
	//more than 10000000 elements scales without memory leaks

	//Tree
	//insert works as intended
	//delete works as intended
	//find works as intended
	//up to 3000 elements can be added after that stack size is not enough for recursion
	//TODO implement different traversals

	//TODO create vector
	//TODO create Queue
	//TODO create AVLTree

	return 0;
}

