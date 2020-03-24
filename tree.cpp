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
void tree::_delete(node*& wurzel, int v)
{
	node* vater = nullptr;

	node* curent = wurzel;

	searchWert(curent, v, vater);

	if (curent == nullptr)
		return;

	if (curent->left == nullptr && curent->right == nullptr)
	{
		if (curent != wurzel)
		{
			if (vater->left == curent)
				vater->left = nullptr;
			else
				vater->right = nullptr;
		}
		else
			wurzel = nullptr;

		free(curent);	
	}

	else
		if (curent->left && curent->right)
		{
			node* next = minimumWert(curent->right);

			int val = next->wert;

			_delete(wurzel, next->wert);

			curent->wert = val;
		}
		else
		{
			node* sohn = (curent->left) ? curent->left : curent->right;

			if (curent != wurzel)
			{
				if (curent == vater->left)
					vater->left = sohn;
				else
					vater->right = sohn;
			}

			else
				wurzel = sohn;

			free(curent);
		}
}
node* tree::minimumWert(node* curent)
{
	while (curent->left != nullptr) {
		curent = curent->left;
	}
	return curent;
}
void tree::searchWert(node*& curent, int v, node*& vater)
{
	while (curent != nullptr && curent->wert != v)
	{
		vater = curent;

		if (v < curent->wert)
			curent = curent->left;
		else
			curent = curent->right;
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

