// MyContainers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyStack.h"

int main()
{
	MyStack<int> Stack;
	for (int i = 0; i < 100000; ++i)
	{
		Stack.push(i);
	}
	//Stack.testPrint();
	for (int i = 0; i < 50000; ++i)
	{
		std::cout << Stack.pop() << std::endl;
	}
	return 0;
}

