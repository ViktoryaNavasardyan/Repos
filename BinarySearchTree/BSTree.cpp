#include <iostream>
#include<stack>
#include <queue>
#include "BSTree.h"

BinSTree::BinSTree()
{
	root = 0;
}

BinSTree::~BinSTree() {}

void BinSTree::Insert(int v)
{
	if (root != 0)
	{
		Insert(v, root);
	}
	else
	{
		root = new TreeNode;
		root->info = v;
		root->left = 0;
		root->right = 0;
	}
}

void BinSTree::Insert(int v, TreeNode* n)
{
	if (n->info > v)
	{
		if (n->left != 0)
		{
			Insert(v, n->left);
		}
		else
		{
			n->left = new TreeNode;
			n->left->info = v;
			n->left->left = 0;
			n->left->right = 0;
		}
	}
	else
	{
		if (n->right != 0)
		{
			Insert(v, n->right);
		}
		else
		{
			n->right = new TreeNode;
			n->right->info = v;
			n->right->left = 0;
			n->right->right = 0;
		}
	}
}

TreeNode* BinSTree::Search(int v, TreeNode* n)
{
	if (n != 0)
	{
		if (n->info == v)
		{
			return n;
		}
		else
		{
			if (n->info > v)
			{
				Search(v, n->left);
			}
			else
			{
				Search(v, n->right);
			}
		}
	}
	else {
		//cout << "No element" << endl;
		return 0;
	}
}

TreeNode* BinSTree::Search(int v)
{
	return Search(v, root);
}

TreeNode* BinSTree::Getroot()
{
	return root;
}


bool BinSTree::GetInfo(TreeNode* t, int& value)
{
	if (t == NULL) {
		return false;
	}
	value = t->info;
	return true;
}

BinSTree::BinSTree(int* a, int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
	{
		this->Insert(a[i]);
	}
}

void visit1(TreeNode* a)
{
	if (!a) return;
	cout << a->info * 10<< " ";
}
//ռեկուրսիվ
void BinSTree::preOrder(TreeNode* t, void visit(TreeNode* a))
{
	if (t != NULL)
	{
		visit(t);
		preOrder(t->left, visit);
		preOrder(t->right, visit);
	}
}

//տպել ծառը 90 աստիճան շրջված
void BinSTree:: Print_tree90(TreeNode* t, int level)
{
	if (t != NULL) {
		Print_tree90(t->Right(), level + 1);
		for (int i = 0; i < 6 * level; i++) {
			cout << " ";
		}
		cout << t->info << endl;
		Print_tree90(t->Left(), level + 1);
	}
}

void BinSTree::InOrder()
{
	TreeNode* r = root;
	stack<TreeNode*> stack;
	while (true) {
		while (r) {
			stack.push(r);
			r = r->Left();
		}
		if (stack.empty())
			return;
		else
		{
			r = stack.top();
			cout << r->info << " ";
			stack.pop();
			r = r->Right();
		}
	}
}

void BinSTree:: PostOrder()
{
	TreeNode* r = root;
	TreeNode* last = 0;
	stack<TreeNode*> stack;
	while (true) {
		while (r) {
			stack.push(r);
			r = r->Left();
		}
		while (!stack.empty()){
			r = stack.top();
			if (!r->Right() || r->Right() == last){
				cout << r->info << " ";
				stack.pop();
				last = r;
			}
			else {
				r = r->Right();
				break;
			}
		}
		if (stack.empty())
			return;
	}
}

void BinSTree::PreOrder()
{
	TreeNode* r = root;
	stack<TreeNode*> stack;
	while (true) {
		while (r) {
			stack.push(r);
			cout << r->info << " ";
			r = r->left;
		}
		if (stack.empty())
			return;
		else {
			r = stack.top();
			stack.pop();
			r = r->right;
		}
	}
}
//լայնակի շրջանցում
void BinSTree::Transverse()
{
	if (root == NULL){
		return;
	}		
	queue<TreeNode*> q;
	q.push(root);		
	queue<int> out;
		while (!q.empty())
		{
			TreeNode* curr = q.front();
			q.pop();
			out.push(curr->info);
			if (curr->left)
				q.push(curr->left);

			if (curr->right)
				q.push(curr->right);
		}
		while (!out.empty())
		{
			cout << out.front() << " ";
			out.pop();
		}
}