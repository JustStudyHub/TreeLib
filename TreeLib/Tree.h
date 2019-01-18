#pragma once
#include "stdafx.h"
#include "Node.h"
class Tree
{
public:
	Tree();
	~Tree();
	void Add(int value);
	Node* Dfs(int value);
	Node* Bfs(int value, void(*funkPtr)(std::queue <int>));
	void Print(std::queue <Node*> treeQueue);
private:
	Node *m_root;
	int m_size;
};

