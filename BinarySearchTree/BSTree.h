#include <iostream>
using namespace std;

class BinSTree;
class TreeNode
{
private:
	TreeNode* left, * right;
public:
	int info = 0;
	TreeNode(const int& item, TreeNode* l = 0, TreeNode* r = 0) :
		info(item), left(l), right(r) {}
	TreeNode() {}
	TreeNode* Left(void)const { return left; }
	TreeNode* Right(void)const { return right; }
	friend class BinSTree;
};

class BinSTree
{
private:
	TreeNode* root;
	void Insert(int, TreeNode*);
	TreeNode* Search(int, TreeNode*);
public:
	BinSTree();
	BinSTree(int*, int);
	//BinSTree(int, TreeNode* = 0, TreeNode* = 0);
	~BinSTree();
	void Insert(int);
	TreeNode* Search(int);
	TreeNode* Getroot();
	bool GetInfo(TreeNode* t,int& value);
	void preOrder(TreeNode*, void visit(TreeNode*));
	//իտերատիվ եղանակներ
	void InOrder();
	void PostOrder();
	void PreOrder();
	//լայնակի շրջանցում
	void Transverse();
	//տպել 90 աստիճան շրջված
	void Print_tree90(TreeNode* t, int level);

};

void visit1(TreeNode* a);

