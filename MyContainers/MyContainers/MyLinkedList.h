#pragma once
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

	void add(T value, int index);	///insert element at index location
	void addFirst(T value);			///insert element in the front
	void addLast(T value);			///insert element at the back

	void del(int index);			///delete element at index location
	void delFirst();				///delete element in the front
	void delLast();					///delete element at the back

	bool findByValue(int &returnValue, T value);	///find element by value, return true if found, and index
	bool findByIndex(T &returnValue, int index);	///find element at index location, return true if found and element
	bool exists(T value);							///check if element exists in the list, return true if it is

	int size();										///return size of the list
	void testPrint();								///prints all list, for testing purposes

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
inline void MyLinkedList<T>::add(T value, int index)
{
	///check validation
	if (index < 0 || index > listSize) { return; }
	else if (index == 0) { addFirst(value); }
	else if (index == listSize) { addLast(value); }
	else if (root == nullptr) { root = new LinkedListNode<T>(value); ++listSize; }
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

template<class T>
inline void MyLinkedList<T>::addFirst(T value)
{
	///check validation
	if (root == nullptr) { root = new LinkedListNode<T>(value); ++listSize; return; }

	///insert element at first location
	LinkedListNode<T> * elementToInsert = root;
	root = new LinkedListNode<T>(value);
	root->next = elementToInsert;
	++listSize;
}

template<class T>
inline void MyLinkedList<T>::addLast(T value)
{
	///check validation
	if (root == nullptr) { root = new LinkedListNode<T>(value); ++listSize; return; }
	LinkedListNode<T> * currentNode = root;
	///traverse to the end 
	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}
	///add element
	currentNode->next = new LinkedListNode<T>(value);
	++listSize;

}

template<class T>
inline void MyLinkedList<T>::del(int index)
{
	///check validation
	if (listSize == 0) { return; }
	else if (index < 0 || index >= listSize) { return; }
	else if (index == 0) { delFirst(); }
	else if (index == listSize-1) { delLast(); }
	else if (root->next == nullptr) { delete root; root = nullptr; --listSize; }
	else if (root == nullptr) { std::cout << "im empty\n"; }
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

template<class T>
inline void MyLinkedList<T>::delFirst()
{
	///check validation
	if (listSize == 0) { return; }
	if (!root) { return; }
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
inline void MyLinkedList<T>::delLast()
{
	///check validation
	if (listSize == 0) { return; }
	if (root == nullptr) { return; }
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
inline bool MyLinkedList<T>::findByValue(int & returnValue, T value)
{
	bool statusReport = false;
	///check validation
	if (listSize==0) { return false; }
	if (!root) { return false; }
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
inline bool MyLinkedList<T>::findByIndex(T & returnValue, int index)
{
	bool statusReport = false;
	///check validation
	if (index < 0 || index > listSize) { return false; }

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
inline bool MyLinkedList<T>::exists(T value)
{
	return findByValue(int noNeed, value);
}

template<class T>
inline int MyLinkedList<T>::size()
{
	return listSize;
}

template<class T>
inline void MyLinkedList<T>::testPrint()
{
	if (!root) { std::cout << "empty\n"; return; }
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

