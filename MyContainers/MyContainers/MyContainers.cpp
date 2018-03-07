// MyContainers.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

#include "MyStack.h"
#include "MyLinkedList.h"
#include "MyList.h"
#include "MyTree.h"
#include "MyVector.h"
#include "MyQueue.h"
#include "MyException.h"

void testStack();

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
	//more than 10000000 elements can be worked with

	//Queue
	//enque works as intended
	//deque works as intended
	//more than 10000000 elements can scale
	/*MyQueue<int> queue;
	for (int i = 0; i < 10000; ++i)
	{
		queue.Enque(i);
	}
	queue.TestPrint();
	std::cout << queue.Size() << std::endl;
	for (int i = 0; i < 1000; ++i)
	{
		std::cout << queue.Deque() << " ";
	}
	std::cout << std::endl;
	std::cout << queue.Size() << std::endl;*/

	testStack();
	//TODO create AVLTree
	//TODO impleent exception throwing to all data structures
	//TODO implement exception handles in case there is no more space to allocate




	return 0;
}

void testStack()
{
	int scale = 10000000000;
	MyStack<int> stack;
	for (int i = 0; i < scale; ++i)
	{
		stack.push(i);
	}
	for (int i = 0; i < scale + 1; ++i)
	{
		stack.pop();
	}

}
