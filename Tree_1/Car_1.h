#pragma once
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int data;
	TreeNode(int d, TreeNode* l = NULL, TreeNode* r = NULL)
	{
		data = d;
		left = l;
		right = r;
	}
	~TreeNode() {}
};

//gagatneri qanak
int size(TreeNode* t)
{
	if (!t) return 0;
	return 1 + size(t->left) + size(t->right);
}

//hashvel terevneri qanaky
int size_l(TreeNode* r)
{
	if (r == 0) return 0;
	if (!r->left && !r->right) return 1;
	return size_l(r->left) + size_l(r->right);
}

//makardaki gagatneri qanaky
int num_level(TreeNode* p, int level)
{
	if (p == 0) return 0;
	if (!level) return 1;
	return num_level(p->left, level - 1) + num_level(p->right, level - 1);
}

//makardakneri qanaky
//es pordzeci nuyn funkcian aranc 2rd parametr grem,
//rekursiayi depqum indz petq e galis ayd parametry tal vor imanam qani 
//makardak em ijel
int levels_count(TreeNode* p, int level)
{
	if (p == 0) return 0;
	int l_level = ++level;
	int r_level = level;
	if (p->left != NULL) {
		l_level = levels_count(p->left, level);
	}
	if (p->right != NULL) {
		r_level = levels_count(p->right, level);
	}
	return r_level > l_level ? r_level : l_level;
}

//tpel cary
void print(TreeNode* r)
{
	queue<TreeNode*> Q1, Q2;
	TreeNode* p = r;
	if (p) Q1.push(r);
	while (1)
	{
		while (!Q1.empty())

		{
			p = Q1.front();
			cout << p->data << " ";
			Q1.pop();
			if (p->left) Q2.push(p->left);
			if (p->right) Q2.push(p->right);
		}

		cout << endl;
		if (Q2.empty()) return;
		while (!Q2.empty())
		{
			Q1.push(Q2.front());
			Q2.pop();
		}
	}
}