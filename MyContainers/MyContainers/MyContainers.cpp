// MyContainers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyStack.h"
#include "MyLinkedList.h"
#include "List.h"

int main()
{
	/*MyStack<int> Stack;
	for (int i = 0; i < 100000; ++i)
	{
		Stack.push(i);
	}
	//Stack.testPrint();
	for (int i = 0; i < 100000; ++i)
	{
		std::cout << Stack.pop() << std::endl;
	}*/
	/*
	MyLinkedList<int> LinkedList;
	
	for (int i = 0; i < 100; ++i)
	{
		LinkedList.add(i*10,i);
	}

	int index = 0;
	int value = 0;

	std::cout << "status: " << LinkedList.findByIndex(value, 50);
	std::cout << "found value: " << value << std::endl;
	std::cout << "status: " << LinkedList.findByValue(index, 95);
	std::cout << "found value: " << index << std::endl;
	//std::cout << LinkedList.size() << std::endl;
	//LinkedList.testPrint();
	*/

	//list 
	//add all methods works as intended
	//del all methods works as intended
	//
	//up tp 10000000 elements scales without memory leaks
	//
	List<int> list;
	for (int i = 0; i < 5; ++i)
	{
		//std::cout << "add nr:" << i << std::endl;
		list.addFirst(i*10);
	}

	//list.add(-1, 0);
	//list.testPrint();
	/*for (int i = 0; i < 10000000; ++i)
	{
		list.delFirst();
	}*/
	list.testPrint();
	int index = 0;
	int value = 0;

	std::cout << "status: " << list.findByIndex(value, 0);
	std::cout << "found value: " << value << std::endl;
	std::cout << "status: " << list.findByValue(index,40);
	std::cout << "found value: " << index << std::endl;

	return 0;
}

