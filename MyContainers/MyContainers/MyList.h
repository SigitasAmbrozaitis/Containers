#pragma once
#include <iostream>
#include "MyException.h"
//**********************************************
//*************   	ListNode      **************
template <class T>
struct ListNode
{
	T value;
	ListNode<T> * previous;
	ListNode<T> * next;
	ListNode(T value);
};

template<class T>
inline ListNode<T>::ListNode(T value)
{
	this->value = value;
	previous = nullptr;
	next = nullptr;
}
//***********************************************

//**********************************************
//************	     List      *****************
template <class T>
class MyList
{
public:
	MyList(); ///constructor

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
	int listSize;			///list size
	ListNode<T> * root;		///list root
	ListNode<T> * end;		///list end
};
//**********************************************

//**********************************************
//************ 	 ListMethods       *************
template<class T>
inline MyList<T>::MyList()
{
	listSize = 0;
	root = nullptr;
	end = nullptr;
}

template<class T>
inline void MyList<T>::Add(T value, int index)
{
	try
	{
		///check validation
		if (index < 0 || index>listSize) { throw MyException(1); }
		else if (index == 0) { AddFirst(value); }
		else if (index == listSize) { AddLast(value); }
		else
		{
			///traverse through list to index
			ListNode<T> * currentNode;
			ListNode<T> * node = new ListNode<T>(value);
			///if index is at the front of list traverse from root
			if (listSize / 2 > index)
			{
				currentNode = root;
				for (int i = 0; i < index - 1; ++i)
				{
					currentNode = currentNode->next;
				}
				ListNode<T> * node = currentNode->next;
				currentNode->next = new ListNode<T>(value);
				node->previous = currentNode->next;
				currentNode->next->next = node;
				currentNode->next->previous = currentNode;
			}
			///if index at the end of list traverse through end
			else
			{
				currentNode = end;
				for (int i = 0; i < listSize - index - 1; ++i)
				{
					currentNode = currentNode->previous;
				}
				ListNode<T> * node = currentNode->previous;
				currentNode->previous = new ListNode<T>(value);
				node->next = currentNode->previous;
				currentNode->previous->previous = node;
				currentNode->previous->next = currentNode;
			}
			++listSize;
		}
	}
	catch (std::exception &ex) { throw; }
}

template<class T>
inline void MyList<T>::AddFirst(T value)
{
	try
	{
		///if list is empty
		if (root == nullptr) { root = new ListNode<T>(value); }
		///if there is 1 element in list
		else if (root != nullptr && end == nullptr) 
		{ 
			end = root;
			root = new ListNode<T>(value);
			root->next = end;
			end->previous = root;
		}
		///if there is >1 elements in list
		else
		{
			ListNode<T> * node = root;
			root = new ListNode<T>(value);
			root->next = node;
			node->previous = root;
		}
		++listSize;
	}
	catch (std::exception &ex) { throw; }

}

template<class T>
inline void MyList<T>::AddLast(T value)
{
	///if list is empty
	try
	{
		if (root == nullptr) { root = new ListNode<T>(value); }
		///if list has one element
		else if (root != nullptr && end == nullptr)
		{
				end = new ListNode<T>(value); 
				root->next = end;
				end->previous = root;
		}
		///if list has >1 elements
		else
		{
			ListNode<T> * node;
			node = new ListNode<T>(value); 		
			node->previous = end;
			end->next = node;
			end = node;
		}
		++listSize;
	}
	catch (std::exception ex) { throw; }

}

template<class T>
inline void MyList<T>::Del(int index)
{
	try
	{
		///if index not in range
		if (index<0 || index > listSize) { throw MyException(1); }
		///if index 0
		if (index == 0) { DelFirst(); return; }
		///if index list size
		if (index == listSize - 1) { DelLast(); return; }
		///traverse to the index
		ListNode<T> * currentNode;
		///if index at front of list go from root
		if (listSize / 2 > index)
		{
			currentNode = root;
			for (int i = 0; i < index-1; ++i)
			{
				currentNode = currentNode->next;
			}
			ListNode<T> * node = currentNode->next;
			currentNode->next = node->next;
			currentNode->next->previous = currentNode;
			delete node;
		}
		///if index at back of list go from end
		else
		{
			currentNode = end;
			for (int i = 0; i < listSize - index-2; ++i)
			{
				currentNode = currentNode->previous;
			}
			ListNode<T> * node = currentNode->previous;
			currentNode->previous = node->previous;
			currentNode->previous->next = currentNode;
			delete node;
		}
		--listSize;
	}
	catch (std::exception &ex) { throw; }
}

template<class T>
inline void MyList<T>::DelFirst()
{
	///if list is empty
	if (root == nullptr) { throw MyException(2); }
	///if there is only root
	else if (root != nullptr && end == nullptr) 
	{ 
		delete root; 
		root = nullptr;
	}
	///if there is only 2 elements root and end
	else if (listSize == 2) { delete root; root = end; root->previous = nullptr; end = nullptr; }
	///if there is more than 2 elements
	else
	{
		ListNode<T> * node = root;
		root = root->next;
		root->previous = nullptr;
		delete node;
	}
	--listSize;
}

template<class T>
inline void MyList<T>::DelLast()
{
	///if list is empty
	if (root == nullptr) { throw MyException(2); }
	///if there is only root
	else if (root != nullptr && end == nullptr) { delete root; root = nullptr;}
	///if there is only 2 elements root and end
	else if (listSize == 2) { delete end; end = nullptr; root->next = nullptr;}
	///if there is more than 2 elements
	else 
	{
		ListNode<T> * node = end;
		end = end->previous;
		end->next = nullptr;
		delete node;
	}
	--listSize;
}//TODO fix deletion, currently memory isnt freed

template<class T>
inline bool MyList<T>::FindByValue(int & returnValue, T value)
{
	bool valueToReturn = false;
	int index = 0;
	ListNode<T> * currentNode = root;
	for (int i = 0; i < listSize; ++i)
	{
		if (currentNode->value == value)
		{
			returnValue = index;
			valueToReturn = true;
			break;
		}
		currentNode = currentNode->next;
		++index;
	}
	return valueToReturn;
}

template<class T>
inline bool MyList<T>::FindByIndex(T & returnValue, int index)
{
	bool valueToReturn = false;
	///return false if out of bounds
	if (listSize == 0) { throw MyException(2); }
	else if (index < 0 || index>listSize - 1) { throw MyException(1); }
	ListNode<T> * currentNode;
	///if index at start start from root
	if (listSize / 2 > index) 
	{
		currentNode = root;
		for (int i = 0; i < index; ++i)
		{
			currentNode = currentNode->next;
		}
	}
	///if index at back start from end
	else
	{
		currentNode = end;
		for (int i = 0; i < listSize - index-1; ++i)
		{
			currentNode = currentNode->previous;
		}
	}
	returnValue = currentNode->value;
	valueToReturn = true;
	return valueToReturn;
}

template<class T>
inline bool MyList<T>::Exists(T value)
{
	int discard;
	return FindByValue(discard, value); 
}

template<class T>
inline int MyList<T>::Size()
{
	return listSize;
}

template<class T>
inline void MyList<T>::TestPrint()
{
	ListNode<T> * currentNode;
	///print size
	std::cout << "size: " << listSize << std::endl;
	///from root to end;
	if (root != nullptr)
	{
		std::cout << "-> : ";
		currentNode = root;
		for (int i = 0; i < listSize; ++i)
		{
			std::cout << currentNode->value << " ";
			currentNode = currentNode->next;
		}
		std::cout << std::endl;
	}
	///from end to root
	if (end != nullptr)
	{
		std::cout << "<- :";
		currentNode = end;
		for (int i = 0; i < listSize; ++i)
		{
			std::cout << currentNode->value << " ";
			currentNode = currentNode->previous;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
//**********************************************