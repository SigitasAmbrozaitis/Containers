// MyContainers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyStack.h"
#include "MyLinkedList.h"

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
	return 0;
}

