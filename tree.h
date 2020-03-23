#pragma once
#include "node.h"
#include <string>
using std :: string;
class tree: public node
{
public:
	node* wurzel;
	tree();
	void insert(int v, node tree);
	void _delete(int v, node tree);
	string inorder(node n);
	string preorder(node n);
	string postorder(node n);
	int countNodes(node n);
	int countEdges(node n);
	int height(node n);
	
};


