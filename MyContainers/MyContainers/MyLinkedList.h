#pragma once
#include <iostream>
#include "MyException.h"
//**********************************************
//**********	LinkedListNode      ************
template <class T>
struct LinkedListNode
{
	T value;					/// node value
	LinkedListNode<T>  * next;	///node pointer to the next element
	LinkedListNode(T value);	///constructor
};
template<class T>
inline LinkedListNode<T>::LinkedListNode(T value)
{
	this->value = value;
	next = nullptr;
}
//***********************************************

//**********************************************
//************	LikedList      *****************
template <class T>
class MyLinkedList
{
public:
	MyLinkedList();					///constructor

	void Add(T value, int index);	///insert element at index location
	void AddFirst(T value);			///insert element in the front
	void AddLast(T value);			///insert element at the back

	void Del(int index);			///delete element at index location
	void DelFirst();				///delete element in the front
	void DelLast();					///delete element at the back

	bool FindByValue(int &returnValue, T value);	///find element by value, return true if found, and index
	bool FindByIndex(T &returnValue, int index);	///find element at index location, return true if found and element
	bool Exists(T value);							///check if element exists in the list, return true if it is

	int Size();										///return size of the list
	void TestPrint();								///prints all list, for testing purposes

protected:
private:
	int listSize;				///list size
	LinkedListNode<T> * root;   ///list start
};
//**********************************************

//**********************************************
//*********	 LinkedListMethods     *************
template<class T>
inline MyLinkedList<T>::MyLinkedList()
{
	listSize = 0;
	root = nullptr;
}

template<class T>
inline void MyLinkedList<T>::Add(T value, int index)
{
	try
	{
		///check validation
		if (index < 0 || index > listSize) { throw MyException(1); }
		else if (index == 0) { AddFirst(value); }
		else if (index == listSize) { AddLast(value); }
		else if (root == nullptr) 
		{ 
			root = new LinkedListNode<T>(value);
			++listSize; 
		}
		else
		{
			///locate where element must be inserted to
			LinkedListNode<T> * currentNode = root;
			for (int i = 0; i < index-1; ++i)
			{
				currentNode = currentNode->next;
			}
			///inser element to found location
			LinkedListNode<T> *temp = currentNode->next;
			currentNode->next = new LinkedListNode<T>(value);
			currentNode->next->next = temp;
			++listSize;
		}
	}
	catch (std::exception &ex) { throw; }
}

template<class T>
inline void MyLinkedList<T>::AddFirst(T value)
{
	try
	{
		///check validation
		if (root == nullptr) { root = new LinkedListNode<T>(value); }
		///insert element at first location
		else
		{
			LinkedListNode<T> * elementToInsert = root;
			root = new LinkedListNode<T>(value);
			root->next = elementToInsert;
		}
		++listSize;
	}
	catch (std::exception &ex) { throw; }
}

template<class T>
inline void MyLinkedList<T>::AddLast(T value)
{
	try
	{
		///check validation
		if (root == nullptr) { root = new LinkedListNode<T>(value); }
		else 
		{
			LinkedListNode<T> * currentNode = root;
			///traverse to the end 
			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			///add element
			currentNode->next = new LinkedListNode<T>(value);
		}
		++listSize;
	}
	catch (std::exception &ex) { throw; }
}

template<class T>
inline void MyLinkedList<T>::Del(int index)
{
	try 
	{
		///check validation
		if (listSize == 0) { throw MyException(2); }
		else if (index < 0 || index >= listSize) { throw MyException(1); }
		else if (index == 0) { DelFirst(); }
		else if (index == listSize-1) { DelLast(); }
		else if (root->next == nullptr) { delete root; root = nullptr; --listSize; }
		else if (root == nullptr) { throw MyException(2); }
		else
		{
			///traverse to index-1
			LinkedListNode<T> * currentNode = root;
			for (int i = 0; i < index - 1; ++i)
			{
				currentNode = currentNode->next;
			}
			///delete elemnt at index
			LinkedListNode<T> * temp = currentNode->next;
			currentNode->next = temp->next;
			delete temp;
			--listSize;
		}
	}
	catch (std::exception &ex) { throw; }

}

template<class T>
inline void MyLinkedList<T>::DelFirst()
{
	///check validation
	if (listSize == 0) { throw MyException(2); }
	if (root == nullptr) { throw MyException(2); }
	if (root->next == nullptr) { delete root; root = nullptr;}
	else
	{
		///delete first element
		LinkedListNode<T> * temp = root;
		root = root->next;
		delete temp;
	}
	--listSize;
}

template<class T>
inline void MyLinkedList<T>::DelLast() //TODO fix deletion, currently memory isnt freed
{
	///check validation
	if (listSize == 0) { throw MyException(2); }
	if (root == nullptr) { throw MyException(2); }
	if (root->next == nullptr) { delete root; root = nullptr; }
	///traverse to the last element
	LinkedListNode<T> * currentNode = root;
	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}
	///delete last element
	delete currentNode->next;
	currentNode->next = nullptr;
	--listSize;
}

template<class T>
inline bool MyLinkedList<T>::FindByValue(int & returnValue, T value)
{
	bool statusReport = false;
	///check validation
	if (listSize==0) { throw MyException(2); }
	if (root == nullptr) { throw MyException(2); }
	///traverse through the list, count index, search for element
	LinkedListNode<T> * currentNode = root;
	int index = 0;
	while (currentNode)
	{
		if (currentNode->value == value)
		{
			statusReport = true;
			returnValue = index;
			break;
		}
		currentNode = currentNode->next;
		++index;
	}
	///return true if element is found
	return statusReport;
}

template<class T>
inline bool MyLinkedList<T>::FindByIndex(T & returnValue, int index)
{

	bool statusReport = false;
	///check validation
	if (index < 0 || index > listSize) { throw MyException(1); }

	///traverse through list at the index
	LinkedListNode<T> * currentNode = root;
	for (int i = 0; i < index; ++i)
	{
		currentNode = currentNode->next;
	}
	returnValue = currentNode->value;
	statusReport = true;
	///return true if element is found
	return statusReport;
}

template<class T>
inline bool MyLinkedList<T>::Exists(T value)
{
	int discard;
	return FindByValue(discard, value);
}

template<class T>
inline int MyLinkedList<T>::Size()
{
	return listSize;
}

template<class T>
inline void MyLinkedList<T>::TestPrint()
{
	if (root == nullptr) { throw MyException(2); }
	std::cout << listSize << ": ";
	LinkedListNode<T> * currentNode = root;
	int counter = 0;
	while (currentNode != nullptr)
	{
		std::cout << currentNode->value << " ";
		currentNode = currentNode->next;
		++counter;
	}
	std::cout << std::endl;
}

//**********************************************

