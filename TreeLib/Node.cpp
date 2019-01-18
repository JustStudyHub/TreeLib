#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	this->m_parent = nullptr;
	this->m_leftChild = nullptr;
	this->m_rightChild = nullptr;
}
Node::Node(int n)
{
	this->m_parent = nullptr;
	this->m_leftChild = nullptr;
	this->m_rightChild = nullptr;
	this->value = n;
}
Node::~Node()
{

}
int Node::GetValue()const
{
	return value;
}
Node* Node::GetLeftChild()const
{
	return m_leftChild;
}
Node* Node::GetRightChild()const
{
	return m_rightChild;
}
Node* Node::GetParent()const
{
	return m_parent;
}
void Node::SetLeftChild(int value)
{
	m_leftChild = new Node(value);
}
void Node::SetRightChild(int value)
{
	m_rightChild = new Node(value);
}
void Node::SetParent(Node* parent)
{
	this->m_parent = parent;
}
