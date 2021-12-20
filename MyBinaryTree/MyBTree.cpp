#include <iostream>
#include <queue>
#include "MyBTree.h"
using namespace std;

//gagatneri qanak
int Count_of_nodes(TreeNode* root)
{
	if (!root) return 0;
	return 1 + Count_of_nodes(root->left) + Count_of_nodes(root->right);
}

//terevneri qanaky
int Count_of_leaves(TreeNode* t)
{
	if (t == 0) return 0;
	if (!t->left && !t->right) return 1;
	return Count_of_leaves(t->left) + Count_of_leaves(t->right);
}

// tvyal makardaki gagatneri qanaky
int Count_of_each_level(TreeNode* p, int level)
{
	if (p == 0) return 0;
	if (!level) return 1;
	return Count_of_each_level(p->left, level - 1) + Count_of_each_level(p->right, level - 1);
}

//tpel cary 90 astijn shrjac
void Print_tree(TreeNode* t, int level)
{
	if (t != NULL) {
		Print_tree(t->right, level + 1);
		for (int i = 0; i < shift * level; i++) {
			cout << " ";
		}
		cout << t->data << endl;
		Print_tree(t->left, level + 1);
	}
}

//cari barzrutyuny

int High(TreeNode* root)
{
	if (root == NULL)
		return - 1;
	int left = High(root->left);
	int right = High(root->right);
	//veradardznel aj ev dzax juxeri bardzrutyunneric mecaguyny
	return (left > right ? left : right) + 1;
}