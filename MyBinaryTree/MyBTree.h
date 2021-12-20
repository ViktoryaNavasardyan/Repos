#pragma once
#include <iostream>

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
int Count_of_nodes(TreeNode* );

//terevneri qanaky
int Count_of_leaves(TreeNode* );

// tvyal makardaki gagatneri qanaky
int Count_of_each_level(TreeNode* , int );

//tpel cary 90 astijn shrjac
const int shift = 5;
void Print_tree(TreeNode* , int );

//cari bardzrutyuny
int High(TreeNode*);