#pragma once
#include <iostream>
using namespace std;

class BSTree;
class Node
{
private:
	Node* left, * right;
public:
	int info = 0;
	Node(const int& item, Node* l = 0, Node* r = 0) :
		info(item), left(l), right(r) {}
	Node() {}
	Node* Left(void)const { return left; }
	Node* Right(void)const { return right; }
	friend class BSTree;
};

class BSTree
{
private:
	Node* root;
	void Insert(int, Node*);
	Node* Search(int, Node*);
public:
	BSTree();
	BSTree(int*, int);
	~BSTree();
	void Insert(int);
	Node* Search(int);
	Node* GetRoot();
	bool GetInfo(Node* t, int& value);
	void InOrder();
	void PostOrder();
	void Transverse();
	void Print_tree90(Node* t, int level);

	int inOrder_height(Node* root);
	bool IsFull();
	bool Is_Full_Rec(Node* r);

	int Count_of_leaves(Node* t);
	void Tree_Leaf(Node* a);
	int High(Node* root);
	void Tree_High(Node* a);
	int GetFullCount(Node* node);
};

