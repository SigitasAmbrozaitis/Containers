#pragma once
#include <iostream>
#include "MyException.h"
//**********************************************
//*************   	TreeNode      **************
template<class T>
struct TreeNode
{
	T value;
	TreeNode<T> *left;
	TreeNode<T> * right;
	TreeNode(T value);
};

template<class T>
inline TreeNode<T>::TreeNode(T value)
{
	this->value = value;
	left = nullptr;
	right = nullptr;
}
//***********************************************

//**********************************************
//************	     Tree      *****************
template <class T>
class MyTree
{
public:
	MyTree();
	void Insert(T value);
	void Delete(T value);
	bool FindByValue(T value);
	int Size();

	void Display();
	void InOrder();
	void PreOrder();
	void PostOrder();

protected:
private:
	TreeNode<T> * root;
	int treeSize;									///treesize
	void Insert(TreeNode<T>*& node, T value);		///insertion
	void Delete(TreeNode<T>*& node, T value);		///deletion
	bool FindByValue(TreeNode<T>*& node, T value);	///find element by value and return true if found
	T FindMinNode(TreeNode<T> *& node);				///find smallest value node and delete it returning its value

	//output traversals
	void Display(TreeNode<T> *& node, int level);
	void InOrder(TreeNode<T> *& node);
	void PreOrder(TreeNode<T> *& node);
	void PostOrder(TreeNode<T> *& node);			
};
//**********************************************

//**********************************************
//************ 	 ListMethods       *************

//**********************************************
//**************** Public!! ********************
//**********************************************
template<class T>
inline MyTree<T>::MyTree()
{
	root = nullptr;
	treeSize = 0;
}

template<class T>
inline void MyTree<T>::Insert(T value)
{
	try { Insert(root, value); }
	catch (std::exception &ex) { throw; }
}

template<class T>
inline void MyTree<T>::Delete(T value)
{
	try
	{
		if (root == nullptr) { throw MyException(2); }
		Delete(root, value);
	}
	catch (std::exception &ex) { std::cout << ex.what() << std::endl; }
	
}

template<class T>
inline bool MyTree<T>::FindByValue(T value)
{
	return FindByValue(root, value);
}

template<class T>
inline int MyTree<T>::Size()
{
	return treeSize;
}
template<class T>
inline void MyTree<T>::Display()
{
	Display(root, 0);


	std::cout << std::endl;
	std::cout << std::endl;
}

template<class T>
inline void MyTree<T>::InOrder()
{
	InOrder(root);
}

template<class T>
inline void MyTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T>
inline void MyTree<T>::PostOrder()
{
	PostOrder(root);
}

//**********************************************
//**************** Private!! *******************
//**********************************************
template<class T>
inline void MyTree<T>::Insert(TreeNode<T>*& node, T value)
{
	try
	{
		if (node == nullptr) ///insert element
		{ 
			node = new TreeNode<T>(value);
			++treeSize;
		}
		///go left
		else if (value < node->value) { Insert(node->left, value); }
		///go right
		else { Insert(node->right, value); }
	}
	catch (std::exception &ex) { throw; }
}

template<class T>
inline void MyTree<T>::Delete(TreeNode<T>*& node, T value)
{
	///traverse to the node that need deletion
	if (node == nullptr) { return; }
	if (node->value == value)
	{
		TreeNode<T> * temp = node;
		///if has no childs delete
		if (node->right == nullptr && node->left == nullptr) { delete node; node = nullptr; }
		///if node has one child, that child takes its position
		else if (node->left != nullptr && node->right == nullptr) { node = node->left; delete temp; }	///if it has left child
		else if (node->right != nullptr && node->left == nullptr) { node = node->right; delete temp; }	///if it has right child
		///if node has 2 childs it switches places with rigt tree lowest value node
		else { node->value = FindMinNode(node->right); }
		--treeSize;
	}
	else if (node->value > value) { Delete(node->left, value); }
	else { Delete(node->right, value); }

}

template<class T>
inline bool MyTree<T>::FindByValue(TreeNode<T>*& node, T value)
{
	if (node == nullptr) { return false; }			///node is nullptr element was not found
	else if (node->value == value) { return true; }	///if node == value element was found
	else if (value < node->value) { return FindByValue(node->left, value); }	///if node value < value go left
	else { return FindByValue(node->right, value); }							///if node value < value go right
}

template<class T>
inline T MyTree<T>::FindMinNode(TreeNode<T>*& node)
{
	if (node->left == nullptr)
	{
		T valueToReturn;
		TreeNode<T>*temporaryNode = node;
		valueToReturn = node->value;
		node = node->right;
		delete temporaryNode;
		return valueToReturn;
	}
	else {
		return FindMinNode(node->left);
	}
}

template<class T>
inline void MyTree<T>::Display(TreeNode<T>*& node, int level)
{
	if (node == nullptr) { return; }

	Display(node->right, level + 1);
	std::cout << std::endl;
	for (int i = 0; i < level; ++i)
	{
		std::cout << "     ";
	}
	std::cout << node->value << ":";
	Display(node->left, level + 1);
}
//**********************************************
//**********************************************