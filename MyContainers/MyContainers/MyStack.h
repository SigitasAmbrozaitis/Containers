#pragma once
#include <iostream>
#include "MyException.h"
//**********************************************
//*************		StackNode      *************
template <class T>
struct StackNode
{
	T value;			//node value
	StackNode<T> * next;//pointer to next value
	StackNode(T value);	//node constructor
};

template<class T>
inline StackNode<T>::StackNode(T value)
{
	this->value = value;
	next = nullptr;
}
//***********************************************

//**********************************************
//*************		Stack      *****************
template <class T>
class MyStack
{
public:

	MyStack();				//constructor
	void Push(T value);		//standart push operation
	T Pop();				//standart pop operation

	void TestPrint();		//full stack output for testing

protected:
private:
	StackNode<T> * root;	//top of stack

	void TestPrint(StackNode<T> *& node);	//full stack output for testing

};
//**********************************************

//**********************************************
//***********	StackMethods     ***************
template<class T>
inline MyStack<T>::MyStack()
{
	root = nullptr;
}

template<class T>
inline void MyStack<T>::Push(T value)
{
	try
	{
		if (root == nullptr) { root = new StackNode<T>(value); }
		else
		{
			StackNode<T> * temp = root;
			root = new StackNode<T>(value);	
			root->next = temp;
		}
	}
	catch (std::exception &ex) { throw; }

}

template<class T>
inline T MyStack<T>::Pop()
{
		if (root == nullptr) { throw MyException(2); }
		T valueToReturn = root->value;
		StackNode<T> * temp = root;
		root = root->next;
		delete temp;
		return valueToReturn;
}

template<class T>
inline void MyStack<T>::TestPrint()
{
	if (root == nullptr){ throw MyException(2); }
	TestPrint(root);
}

template<class T>
inline void MyStack<T>::TestPrint(StackNode<T> *& node)
{
	if (node==nullptr) { return; }
	std::cout << node->value << std::endl;
	TestPrint(node->next);
}

//**********************************************
