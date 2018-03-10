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

#define SIZE 1000000
void testStack();
void testLinkedList();
void testList();
void testTree();
void testVector();
void testQueue();

int main()
{
//TODO create AVLTree
//TODO impleent exception throwing to all data structures
//TODO implement exception handles in case there is no more space to allocate

	testStack();
	testLinkedList();
	testList();
	testTree();
	testVector();
	testQueue();

return 0;
}
//Stack
//push works as intended
//pop works as intended
//scales more than 10000000, should go to infinity, aborted due to long test times
//exceptions added
void testStack()
{
	std::cout << "testing stack"  << std::endl;
	int scale = SIZE;

	MyStack<int> stack;

	for (int i = 0; i < scale; ++i)
	{
		try { stack.Push(i); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished allocating" << std::endl;


	//stack.TestPrint();
	for (int i = 0; i < scale + 1; ++i)
	{
		try { stack.Pop(); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished deleteing" << std::endl;


	std::cout << "***********************************" << std::endl << std::endl;
}

//LinkedList
// add all methods works as intended
// del all methods works as intended
// find all methods works as intended
// more than 100000 elements scales without memory leaks
//exceptions implemented
//TODO fix deletion, currently memory isnt freed
void testLinkedList()
{
	std::cout << "testing LinkedList"  << std::endl;
	int scale = SIZE;
	MyLinkedList<int> list;
	for (int i = 0; i < scale; ++i)
	{
		try { list.AddFirst(i); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished allocating" << std::endl;
	for (int i = 0; i < scale + 1; ++i)
	{
		try { list.DelFirst(); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished deleteing" << std::endl;
	int returnedValue = 0;
	bool returnStatus = false;
	try { returnStatus = list.FindByIndex(returnedValue, 20000); }
	catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	std::cout << "ReturnedValue: " << returnedValue << " ReturnStatus: " << returnStatus << std::endl;

	try { returnStatus = list.FindByValue(returnedValue, 5000000); }
	catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	std::cout << "ReturnedValue: " << returnedValue << " ReturnStatus: " << returnStatus << std::endl;

	try { returnStatus = list.Exists(50); }
	catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	std::cout << " ReturnStatus: " << returnStatus << std::endl;
	std::cout << "***********************************" << std::endl << std::endl;

}

//List 
//add all methods works as intended
//del all methods works as intended
//find all methods works as intended
//more than 10000000 elements scales without memory leaks
//TODO fix deletion, currently memory isnt freed
void testList()
{
	std::cout << "testing Listt" <<  std::endl;
	int scale = SIZE;
	MyList<int> list;

	for (int i = 0; i < scale; ++i)
	{
		try { list.AddLast(i); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished allocating" << std::endl;

	for (int i = 0; i < scale + 1; ++i)
	{	
		try { list.DelFirst(); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished deleteing" << std::endl;

	int returnedValue = 0;
	bool returnStatus = false;

	try { returnStatus = list.FindByIndex(returnedValue, 20000); }
	catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	std::cout << "ReturnedValue: " << returnedValue << " ReturnStatus: " << returnStatus << std::endl;

	try { returnStatus = list.FindByValue(returnedValue, 5000000); }
	catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	std::cout << "ReturnedValue: " << returnedValue << " ReturnStatus: " << returnStatus << std::endl;

	try { returnStatus = list.Exists(50); }
	catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	std::cout << " ReturnStatus: " << returnStatus << std::endl;
	std::cout << "***********************************" << std::endl << std::endl;
}

//Tree
//insert works as intended
//delete works as intended
//find works as intended
//more than 3000 elements can be worked with after that stack size is not enough for recursion
//TODO implement different traversals
void testTree()
{
	std::cout << "testing tree" << std::endl;
	int scale = SIZE;
	MyTree<int> tree;
	for (int i = 0; i < scale; ++i)
	{
		int rnd = rand() % scale;
		try { tree.Insert(rnd); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished allocating" << std::endl;
	//tree.Display();
	//std::cout << "Size: "<<tree.Size() << std::endl;
	for (int i = 0; i < scale+1; ++i)
	{
		int rnd = rand() % scale;
		try { tree.Delete(i); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	//tree.Display();
	//std::cout << "Size: " << tree.Size() << std::endl;
	std::cout << "finished deleteing" << std::endl;
	std::cout << "***********************************" << std::endl << std::endl;
}

//Vector COMPLETED
//insert works as intended
//delete works as intended
//find works as intended
//more than 10000000 elements can be worked with
void testVector()
{
	std::cout << "testing vector" << std::endl;
	int scale = SIZE;
	MyVector<int> vector(100000);
	//bool finished = false;
	for (int i = 0; i < scale; ++i)
	{
		try { vector.Insert(i, i/2); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished allocating" << std::endl;
	for (int i = scale +1; i >= -1; --i)
	{
		try { vector.Delete(i); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; break; }
		catch (std::exception &ex) { if (i % 100000 == 0) { std::cout << "exception: " << ex.what() << std::endl; } }
		if (i % 100000== 0) { std::cout << "i:" << i << std::endl; }

	}
	std::cout << "finished deleteing" << std::endl;
	std::cout << "***********************************" << std::endl << std::endl;
}
//Queue
//enque works as intended
//deque works as intended
//more than 10000000 elements can scale
void testQueue()
{
	std::cout << "testing queue" << std::endl;
	int scale = SIZE;
	MyQueue<int> queue;
	for (int i = 0; i < scale; ++i)
	{
		try { queue.Enque(i); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished allocating" << std::endl;
	for (int i = 0; i < scale+2; ++i)
	{
		try { queue.Deque(); }
		catch (std::bad_alloc &ex) { std::cout << ex.what() << std::endl; std::cout << i << std::endl; break; }
		catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	}
	std::cout << "finished deleteing" << std::endl;
	std::cout << "***********************************" << std::endl << std::endl;
}

