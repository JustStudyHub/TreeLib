#include "stdafx.h"
#include "Tree.h"
#include "Node.h"

Tree::Tree()
{
	m_root = nullptr;
	m_size = 0;
}
Tree::~Tree()
{
	if (m_root == nullptr)
	{
		return;
	}
	std::queue <Node*> treeQueue;
	Node* temp;
	treeQueue.push(m_root);
	while (treeQueue.size())
	{
		if (treeQueue.front()->GetLeftChild() != nullptr)
		{
			treeQueue.push(treeQueue.front()->GetLeftChild());
		}
		if (treeQueue.front()->GetRightChild() != nullptr)
		{
			treeQueue.push(treeQueue.front()->GetRightChild());
		}
		temp = treeQueue.front();
		treeQueue.pop();
		delete temp;
	}
}
void Tree::Add(int value)
{
	if (m_root == nullptr)
	{
		m_root = new Node(value);
		m_size = 1;
		return;
	}
	Node *temp = m_root;
	++m_size;
	while (true)
	{
		if (value < temp->GetValue())
		{
			if (temp->GetLeftChild() == nullptr)
			{
				(*temp).SetLeftChild(value);
				temp->GetLeftChild()->SetParent(temp);
				break;
			}
			temp = temp->GetLeftChild();
		}
		else
		{
			if (temp->GetRightChild() == nullptr)
			{
				(*temp).SetRightChild(value);
				temp->GetRightChild()->SetParent(temp);
				break;
			}
			temp = temp->GetRightChild();
		}
	}
}
Node* Tree::Dfs(int value)
{
	if (m_root == nullptr)
	{
		return nullptr;
	}
	std::stack <Node*> treeStack;
	Node* temp = nullptr;
	treeStack.push(m_root);
	while (treeStack.size())
	{
		temp = treeStack.top();
		treeStack.pop();
		if (temp->GetValue() == value)
		{
			return temp;
		}
		if (temp->GetLeftChild() != nullptr)
		{
			treeStack.push(temp->GetLeftChild());
		}
		if (temp->GetRightChild())
		{
			treeStack.push(temp->GetRightChild());
		}
	}
	return nullptr;
}
Node* Tree::Bfs(int value, void(*funkPtr)(std::queue <int>))
{
	if (m_root == nullptr)
	{
		return nullptr;
	}
	std::queue <Node*> treeQueue;
	std::queue <int> printQueue;
	treeQueue.push(m_root);
	printQueue.push(m_root->GetValue());
	while (treeQueue.size())
	{
		if (treeQueue.front()->GetValue() == value)
		{
			funkPtr(printQueue);
			return treeQueue.front();
		}
		if (treeQueue.front()->GetLeftChild() != nullptr)
		{
			treeQueue.push(treeQueue.front()->GetLeftChild());
			printQueue.push(treeQueue.front()->GetLeftChild()->GetValue());
		}
		if (treeQueue.front()->GetRightChild())
		{
			treeQueue.push(treeQueue.front()->GetRightChild());
			printQueue.push(treeQueue.front()->GetRightChild()->GetValue());
		}
		treeQueue.pop();
	}
	return nullptr;
}
void Tree::Print(std::queue <Node*> printQueue)
{
	while (printQueue.size())
	{
		if (printQueue.front()->GetParent() != nullptr)
		{
			std::cout << printQueue.front()->GetValue() << " p= " << printQueue.front()->GetParent()->GetValue() << std::endl;
		}
		else
		{
			std::cout << printQueue.front()->GetValue() << std::endl;
		}
		printQueue.pop();
	}
}

