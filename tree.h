#pragma once
#include "node.h"
#include <string>
using std :: string;
class tree
{
	friend class node;
public:
	node* wurzel;
	tree();
	void insert(int v);
	void _delete(node *&wurzel ,int v);
	string inorder(node* n);
	string preorder(node* n);
	string postorder(node* n);
	int countNodes(node* n);
	node* minimumWert(node* curent);
	void searchWert(node*& curent, int v, node*& vater);
	int countEdges(node* n);
	//int height(node* n);
	
};


