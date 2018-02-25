#pragma once
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
	void push(T value);		//standart push operation
	T pop();				//standart pop operation

	void testPrint();		//full stack output for testing

protected:
private:
	StackNode<T> * root;	//top of stack

	void testPrint(StackNode<T> *& node);	//full stack output for testing

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
inline void MyStack<T>::push(T value)
{
	if (root == nullptr) { root = new StackNode<T>(value); }
	else
	{
		StackNode<T> * temp = root;
		root = new StackNode<T>(value);
		root->next = temp;
	}
}

template<class T>
inline T MyStack<T>::pop()
{
	T valueToReturn = root->value;
	StackNode<T> * temp = root;
	root = root->next;
	delete temp;

	return valueToReturn;
}

template<class T>
inline void MyStack<T>::testPrint()
{
	testPrint(root);
}

template<class T>
inline void MyStack<T>::testPrint(StackNode<T> *& node)
{
	if (!node) { return; }
	std::cout << node->value << std::endl;
	testPrint(node->next);
}

//**********************************************
