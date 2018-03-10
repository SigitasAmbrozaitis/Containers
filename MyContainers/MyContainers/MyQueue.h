#pragma once
#include <iostream>
#include "MyException.h"
//**********************************************
//*************		QueueNode      *************
template <class T>
struct QueueNode
{
	T value;
	QueueNode<T> * next;
	QueueNode(T value);
};

template<class T>
inline QueueNode<T>::QueueNode(T value)
{
	this->value = value;
	next = nullptr;
}
//***********************************************

//**********************************************
//*************		Stack      *****************
template <class T>
class MyQueue
{
public:
	MyQueue();				//constructor
	void Enque(T value);	//standart enque
	T Deque();				//standart deque
	int Size();				//size
	void TestPrint();

protected:
private:

	QueueNode<T> * root;
	QueueNode<T> * end;
	int queueSize;
};

template<class T>
inline MyQueue<T>::MyQueue()
{
	root = nullptr;
	end = nullptr;
	queueSize = 0;
}

template<class T>
inline void MyQueue<T>::Enque(T value)
{
	try
	{
		//if root nullptr create root
		if (root == nullptr) { root = new QueueNode<T>(value); }
		else if (end == nullptr) { end = new QueueNode<T>(value); root->next = end; }
		else
		{
			end->next = new QueueNode<T>(value);
			end = end->next;
		}
		++queueSize;
	}
	catch (std::exception &ex) { throw; }

}

template<class T>
inline T MyQueue<T>::Deque()
{
	T valueToReturn;
	if (root == nullptr) { throw MyException(2); }//TODO implement throw to exit 
	else if (root == end) 
	{
		valueToReturn = root->value;
		delete root; 
		root = nullptr; 
		end = nullptr; 
		--queueSize;
		return valueToReturn;	
	}
	else
	{
		valueToReturn = root->value;
		QueueNode<T> * node = root;
		root = root->next;
		delete node;
		--queueSize;
		return valueToReturn;
	}
}

template<class T>
inline int MyQueue<T>::Size()
{
	return queueSize;
}

template<class T>
inline void MyQueue<T>::TestPrint()
{
	QueueNode<T> * currentNode = root;
	while (currentNode != nullptr)
	{
		std::cout << currentNode->value << " ";
		currentNode = currentNode->next;
	}
	std::cout << std::endl;
}
