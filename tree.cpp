#include "tree.h"
tree::tree()
{
	wurzel = nullptr;
}
void tree::insert(int v) {
	if (wurzel == nullptr) {
		wurzel = new node(v);
	}
	else
	{
		node* zeiger = wurzel;
		while (zeiger) {
			if (zeiger->wert > v) {
				if (zeiger->left == nullptr) {
					zeiger->left = new node(v);
					return;
				}
				zeiger = zeiger->left;
			}
			else
				if (zeiger->wert < v) {
					if (zeiger->right == nullptr) {
						zeiger->right = new node(v);
						return;
					}
					zeiger = zeiger->right;
				}
		}
	}
}
string tree::inorder(node* wurzel) {
	if (wurzel == NULL)
		return "";
	return inorder(wurzel->left) + std::to_string(wurzel->wert) + " " + inorder(wurzel->right);
}
string tree::preorder(node* wurzel) {
	if (wurzel == NULL)
		return "";
	return std::to_string(wurzel->wert) + " " + preorder(wurzel->left) + preorder(wurzel->right);
}string tree::postorder(node* wurtzel) {
	if (wurtzel == NULL)
		return "";
	return postorder(wurtzel->left) + postorder(wurtzel->right) + std::to_string(wurtzel->wert) + " ";
}
void tree::_delete(int v) {
	node* zeiger = wurzel;
	while (zeiger)
	{
		if (zeiger->left != nullptr) {
			if (zeiger->left->wert==v)
			{
				zeiger->left = zeiger->left->right;
				return;
			}
		}
		if (zeiger->right != nullptr) {
			if (zeiger->right->wert == v)
			{
				zeiger->right = zeiger->right->left;
				return;
			}
		}
		if (zeiger->wert < v)
		{
			if (zeiger->right == nullptr) {
				return;
			}
			zeiger = zeiger->right;
		}
		if (zeiger->wert > v)
		{
			if (zeiger->left == nullptr) {
				return;
			}
			zeiger = zeiger->left;
		}

	}
}
int tree::countNodes(node* n) {
	int ct = 1;
	if (n==nullptr)
	{
		return 0;
	}
	else {
		ct = ct + countNodes(n->left);
		ct = ct + countNodes(n->right);
		return ct;
	}
}

