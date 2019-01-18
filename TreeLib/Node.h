#pragma once
#include "stdafx.h"
class Node
{
public:
	Node();
	Node(int n);
	~Node();
	int GetValue()const;
	Node* GetLeftChild()const;
	Node* GetRightChild()const;
	Node* GetParent()const;
	void SetLeftChild(int value);
	void SetRightChild(int value);
	void SetParent(Node* parent);
private:
	Node *m_leftChild;
	Node *m_rightChild;
	Node *m_parent;
	int value;
};

