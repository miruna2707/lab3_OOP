#pragma once
#include "tree.h"
class node:public tree

{
public:
	node(int wert) {
		this->wert = wert;
		left = right = nullptr;
	}

private:
	int wert;
	node* left, * right;
};
