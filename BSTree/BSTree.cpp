#include <iostream>
#include<stack>
#include <queue>
#include "BSTree.h"

BSTree::BSTree()
{
	root = 0;
}

BSTree::~BSTree() {}

void BSTree::Insert(int v)
{
	if (root != 0)
	{
		Insert(v, root);
	}
	else
	{
		root = new Node;
		root->info = v;
		root->left = 0;
		root->right = 0;
	}
}

void BSTree::Insert(int v, Node* n)
{
	if (n->info > v)
	{
		if (n->left != 0)
		{
			Insert(v, n->left);
		}
		else
		{
			n->left = new Node;
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
			n->right = new Node;
			n->right->info = v;
			n->right->left = 0;
			n->right->right = 0;
		}
	}
}

Node* BSTree::Search(int v, Node* n)
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
		return 0;
	}
}

Node* BSTree::Search(int v)
{
	return Search(v, root);
}

Node* BSTree::GetRoot()
{
	return root;
}

bool BSTree::GetInfo(Node* t, int& value)
{
	if (t == NULL) {
		return false;
	}
	value = t->info;
	return true;
}

BSTree::BSTree(int* a, int n)
{
	root = NULL;
	for (int i = 0; i < n; i++)
	{
		this->Insert(a[i]);
	}
}

void BSTree::Print_tree90(Node* t, int level)
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

void BSTree::InOrder()
{
	Node* r = root;
	stack<Node*> stack;
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

void BSTree::PostOrder()
{
	Node* r = root;
	Node* last = 0;
	stack<Node*> stack;
	while (true) {
		while (r) {
			stack.push(r);
			r = r->Left();
		}
		while (!stack.empty()) {
			r = stack.top();
			if (!r->Right() || r->Right() == last) {
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

void BSTree::Transverse()
{
	if (root == NULL) {
		return;
	}
	queue<Node*> q;
	q.push(root);
	queue<int> out;
	while (!q.empty())
	{
		Node* curr = q.front();
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

bool BSTree::IsFull()
{
	queue<Node*> q1, q2;
	Node* r = root;
	int k = 2;
	if (r)
		q1.push(r);
	while (true) {
		while (!q1.empty()) {
			r = q1.front();
			q1.pop();
			if (r->left)
				q2.push(r->left);
			if(r->right)
				q2.push(r->right);
		}

		if (q2.empty())
			return true;
		if (q2.size() != k)
			return false;
		k = k * 2;
		
		while (!q2.empty()){
			q1.push(q2.front());
			q2.pop(); 
		}
	}
}

int BSTree::inOrder_height(Node* root)
{
	Node* r = root;
	stack<Node*> st1;
	stack<int> st2;
	int h = 0;
	int max = 0;
	while (true) {
		while (r) {
			st2.push(h);
			st1.push(r);
			r = r->left;
			h++;
		}
		if (st1.empty())
			return max;
		else {
			r = st1.top();
			st1.pop();
			h = st2.top() + 1;
			st2.pop();
			if (!r->right && !r->left) {
				if (max < h - 1)
					max = h - 1;
			}
			r = r->right;
		}
	}
}

bool BSTree:: Is_Full_Rec(Node* r)
{
	if (r == 0)
		return true;
	if (!r->left && r->right || r->left && !r->right)
		return false;
	return(inOrder_height(r->right) == inOrder_height(r->left)
		&& Is_Full_Rec(r->left) && Is_Full_Rec(r->right));
}

int BSTree::Count_of_leaves(Node* t)
{
	if (t == 0) return 0;
	if (!t->Left() && !t->Right()) return 1;
	return Count_of_leaves(t->Left()) + Count_of_leaves(t->Right());
}

void BSTree::Tree_Leaf(Node* a)
{
	if (a == NULL) return;
	a->info = Count_of_leaves(a);
	Tree_Leaf(a->Left());
	Tree_Leaf(a -> Right());
}

int BSTree::High(Node* root)
{
	if (root == NULL)
		return -1;
	int left = High(root->Left());
	int right = High(root->Right());
	//veradardznel aj ev dzax juxeri bardzrutyunneric mecaguyny
	return (left > right ? left : right) + 1;
}

void BSTree::Tree_High(Node* a)
{
	if (a == NULL) return;
	//	a->info = High(a);
	a->info = inOrder_height(a);
	Tree_High(a->Left());
	Tree_High(a->Right());
}

//bolor noderi qanaky
int BSTree::GetFullCount(Node* node)
{
	if (!node)
		return 0;

	queue<Node*> q;
	int count = 0; 
	q.push(node);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		//if (temp)
			count++;

		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}
	return count;
}