// MyContainers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyStack.h"
#include "MyLinkedList.h"
#include "MyList.h"
#include "MyTree.h"
#include "MyVector.h"

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
	//more than 3000 elements can be worked with after that stack size is not enough for recursion
	//TODO implement different traversals

	//Vector
	//insert works as intended
	//delete works as intended
	//find works as intended
	//moe than 10000000 elements can be worked with

	//TODO create Queue
	//TODO create AVLTree
	//TODO impleent exception throwing to all data structures


	MyVector<int> array;
	for (int i = 0; i < 10000000; ++i)
	{
		array.Insert(i, i);
	}
	//array.Insert(0,);
	array.TestPrint();

	return 0;
}

