#pragma once
template <class T>
struct LinkedListNode
{
	T value;
	LinkedListNode<T>  * next;
	LinkedListNode(T value);
};
template<class T>
inline LinkedListNode<T>::LinkedListNode(T value)
{
	this->value = value;
	next = nullptr;
}

template <class T>
class MyLinkedList
{
public:
	MyLinkedList();

	void add(T value, int index);
	void addFirst(T value);
	void addLast(T value);

	void del(int index);
	void delFirst();
	void delLast();

	bool findByValue(int &returnValue, T value);
	bool findByIndex(T &returnValue, int index);
	bool exists(T value);

	int size();
	void testPrint();

protected:
private:
	int listSize;
	LinkedListNode<T> * root;

	void testPrint(LinkedListNode<T> *& node);

};

template<class T>
inline MyLinkedList<T>::MyLinkedList()
{
	listSize = 0;
	root = nullptr;
}

template<class T>
inline void MyLinkedList<T>::add(T value, int index)
{
	if (index < 0 || index > listSize) { return; }
	else if (index == 0) { addFirst(value); }
	else if (index == listSize) { addLast(value); }
	else if (root == nullptr) { root = new LinkedListNode<T>(value); }
	else
	{
		//locate where element must be inserted to
		LinkedListNode<T> * currentNode = root;
		for (int i = 0; i < index-1; ++i)
		{
			currentNode = currentNode->next;
		}
		//inser element to found location
		LinkedListNode<T> *temp = currentNode->next;
		currentNode->next = new LinkedListNode<T>(value);
		currentNode->next->next = temp;
		++listSize;
		testPrint();//TODO  remove
	}
	
}

template<class T>
inline void MyLinkedList<T>::addFirst(T value)
{
	if (root == nullptr) { root = new LinkedListNode<T>(value); }
	else
	{
		LinkedListNode<T> * elementToInsert = root;
		root = new LinkedListNode<T>(value);
		root->next = elementToInsert;
	}
	++listSize;
	testPrint();//TODO  remove
}

template<class T>
inline void MyLinkedList<T>::addLast(T value)
{
	if (root == nullptr) { root = new LinkedListNode<T>(value); return; }
	LinkedListNode<T> * currentNode = root;
	//traverse to the end 
	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
	}
	//add element
	currentNode->next = new LinkedListNode<T>(value);
	++listSize;
	testPrint();//TODO  remove
}

template<class T>
inline void MyLinkedList<T>::del(int index)
{
	if (listSize == 0) { return; }
	else if (index < 0 || index >= listSize) { return; }
	else if (index == 0) { delFirst(); }
	else if (index == listSize-1) { delLast(); }
	else if (root->next == nullptr) { delete root; root = nullptr; }
	else if (root == nullptr) { std::cout << "im empty\n"; }
	else
	{
		//traverse to index-1
		LinkedListNode<T> * currentNode = root;
		for (int i = 0; i < index - 1; ++i)
		{
			currentNode = currentNode->next;
		}
		LinkedListNode<T> * temp = currentNode->next;
		currentNode->next = temp->next;
		delete temp;
		--listSize;
 		//delete index->next
	}
	testPrint();//TODO  remove
	
}

template<class T>
inline void MyLinkedList<T>::delFirst()
{
	if (listSize == 0) { return; }
	if (!root) { return; }
	if (root->next == nullptr) { delete root; root = nullptr; }
	else
	{
		LinkedListNode<T> * temp = root;
		root = root->next;
		delete temp;
		
	}
	--listSize;
}

template<class T>
inline void MyLinkedList<T>::delLast()
{
	if (listSize == 0) { return; }
	if (!root) { return; }
	if (root->next == nullptr) { delete root; root = nullptr; }
	LinkedListNode<T> * currentNode = root;
	while (currentNode->next->next != nullptr)
	{
		currentNode = currentNode->next;
	}
	delete currentNode->next;
	currentNode->next = nullptr;
	--listSize;
}

template<class T>
inline bool MyLinkedList<T>::findByValue(int & returnValue, T value)
{
	bool statusReport = false;
	if (listSize==0) { return false; }
	if (!root) { return false; }
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
	return statusReport;
}

template<class T>
inline bool MyLinkedList<T>::findByIndex(T & returnValue, int index)
{
	bool statusReport = false;
	if (index < 0 || index > listSize) { return false; }

	LinkedListNode<T> * currentNode = root;
	for (int i = 0; i < index; ++i)
	{
		currentNode = currentNode->next;
	}
	returnValue = currentNode->value;
	statusReport = true;
	
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
	//testPrint(root);
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
	//std::cout << counter << std::endl;
	std::cout << std::endl;
}

template<class T>
inline void MyLinkedList<T>::testPrint(LinkedListNode<T>*& node)
{
	if (!node) { return; }
	std::cout << node->value << " ";
	testPrint(node->next);
}
