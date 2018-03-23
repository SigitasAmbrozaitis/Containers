#pragma once
#include <iostream>
#include "MyException.h"
//**********************************************
//**********	AVLTreeNode      ***************
template <class T>
struct AvlTreeNode
{
	AvlTreeNode(T value);
	AvlTreeNode * left;
	AvlTreeNode * right;
	T data;
	int height;

};
template <class T>
AvlTreeNode<T>::AvlTreeNode(T value)
{
	this->data = value;
	this->left = nullptr;
	this->right = nullptr;
	this->height = -1;
}
//************************************************

//************************************************
//************	AVLTreeList      *****************
template<class T>
class MyAvlTree
{
public:
	MyAvlTree();
	~MyAvlTree();

	void Insert(T value);
	void Delete(T value);
	AvlTreeNode<T> * Find(T value);

	void Display();
	void InOrder();
	void PreOrder();
	void PostOrder();


private:
	AvlTreeNode<T> * root;
	//operations
	void Insert(AvlTreeNode<T> *& node, T value);
	AvlTreeNode<T> * Delete(AvlTreeNode<T> *& node, T value);
	AvlTreeNode<T> * Find(AvlTreeNode<T> *& node, T value);
	//helpers
	int maximum(int value1, int value2);
	int GetNodeHeight(AvlTreeNode<T> *& node);
	int HeightDifference(AvlTreeNode<T> *& node);
	int CalculateNodeHeight(AvlTreeNode<T> *& node);
	AvlTreeNode<T>* FindMinimalNode(AvlTreeNode<T> *& node);
	AvlTreeNode<T>* BalanceNode(AvlTreeNode<T> *node, T value);

	//output
	void Display(AvlTreeNode<T> *& node, int level);
	void InOrder(AvlTreeNode<T> *& node);
	void PreOrder(AvlTreeNode<T> *& node);
	void PostOrder(AvlTreeNode<T> *& node);


	//rotations
	AvlTreeNode<T>* RightRightRotation(AvlTreeNode<T> *& node);
	AvlTreeNode<T>* LeftLeftRotation(AvlTreeNode<T> *& node);

	AvlTreeNode<T>* RightLeftRotation(AvlTreeNode<T> *& node);
	AvlTreeNode<T>* LeftRightRotation(AvlTreeNode<T> *& node);

};

//**************************************************************
//*********************** Public!! *****************************
//**************************************************************

template<class T>
inline MyAvlTree<T>::MyAvlTree()
{
	root = nullptr;
}

template<class T>
inline MyAvlTree<T>::~MyAvlTree()
{
}

template<class T>
inline void MyAvlTree<T>::Insert(T value)
{

	Insert(root, value);

}

template<class T>
inline void MyAvlTree<T>::Delete(T value)
{
	Delete(root, value);
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::Find(T value)
{
	return Find(root, value);
}

template<class T>
inline void MyAvlTree<T>::Display()
{
	Display(root, 0);

	std::cout << std::endl;
	std::cout << std::endl;
}

template<class T>
inline void MyAvlTree<T>::InOrder()
{
	InOrder(root);
}

template<class T>
inline void MyAvlTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T>
inline void MyAvlTree<T>::PostOrder()
{
	PostOrder(root);
}

//**************************************************************
//*********************** Private!! ****************************
//**************************************************************


template<class T>
inline void MyAvlTree<T>::Insert(AvlTreeNode<T>*& node, T value)
{
	if (node == nullptr) 
	{ 
		node = new AvlTreeNode<T>(value); 
	}
	else if (value < node->data) {Insert(node->left, value); }
	else{ Insert(node->right, value); }

	int balanceFactor = HeightDifference(node);
	if (balanceFactor > 1 && value > node->right->data) { node = RightRightRotation(node); }	//RightRightRotation
	if (balanceFactor <-1 && value < node->left->data ) { node = LeftLeftRotation(node);   }	//LeftLeftRotation
	if (balanceFactor > 1 && value < node->right->data) { node = RightLeftRotation(node);  }	//RightLeftRotation
	if (balanceFactor <-1 && value > node->left->data ) { node = LeftRightRotation(node);  }	//LeftRightRotation
	node->height = CalculateNodeHeight(node);
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::Delete(AvlTreeNode<T>*& node, T value)
{
	return NULL;
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::Find(AvlTreeNode<T>*& node, T value)
{
	if (node == nullptr) { return nullptr; }
	else if (node->data == value) { return node; }
	else if (value <= node->data) { return Find(node->left, value); }
	else if (value > node->data) { return Find(node->right, value); }
	return nullptr;
}

template<class T>
inline int MyAvlTree<T>::maximum(int value1, int value2)
{
	return (value1 <= value2 ? value2 : value1);
}

template<class T>
inline int MyAvlTree<T>::GetNodeHeight(AvlTreeNode<T>*& node)
{
	if (node == nullptr) { return -1; }
	else { return node->height; }
}

template<class T>
inline int MyAvlTree<T>::HeightDifference(AvlTreeNode<T>*& node)
{
	if (node == nullptr) { return -1; }
	return GetNodeHeight(node->right) - GetNodeHeight(node->left);
}

template<class T>
inline int MyAvlTree<T>::CalculateNodeHeight(AvlTreeNode<T>*& node)
{
	return maximum(GetNodeHeight(node->left), GetNodeHeight(node->right)) + 1;
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::FindMinimalNode(AvlTreeNode<T>*& node)
{
	AvlTreeNode<T> * currentNode = node;
	while (currentNode->left != nullptr)
	{
		currentNode = currentNode->left;
	}
	return currentNode;
}



template<class T>
inline void MyAvlTree<T>::Display(AvlTreeNode<T>*& node, int level)
{
	if (node == nullptr) { return; }

	Display(node->right, level + 1);
	std::cout << std::endl;
	//std::cout << std::endl; std::cout << std::endl;
	for (int i = 0; i < level; ++i)
	{
		std::cout << "     ";
	}
	std::cout << node->data << ":" << node->height;
	Display(node->left, level + 1);
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::RightRightRotation(AvlTreeNode<T>*& node)
{
	AvlTreeNode<T> * temp = node->right;
	node->right = temp->left;
	temp->left = node;

	node->height = CalculateNodeHeight(node);
	temp->height = CalculateNodeHeight(node);
	return temp;
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::LeftLeftRotation(AvlTreeNode<T>*& node)
{
	AvlTreeNode<T>* temp = node->left;
	node->left = temp->right;
	temp->right = node;

	node->height = CalculateNodeHeight(node);
	temp->height = CalculateNodeHeight(node);

	return temp;
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::RightLeftRotation(AvlTreeNode<T>*& node)
{
	node->right = LeftLeftRotation(node->right);
	return RightRightRotation(node);
}

template<class T>
inline AvlTreeNode<T>* MyAvlTree<T>::LeftRightRotation(AvlTreeNode<T>*& node)
{
	node->left = RightRightRotation(node->left);
	return LeftLeftRotation(node);
}






