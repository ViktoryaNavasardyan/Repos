//#include <iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//struct Node {
//	Node* left, * right; int value, depth;
//};
//class BinaryTree
//{
//	Node* root;
//	void Insert(int, Node*);
//	Node* Search(int, Node*);
//public:
//	BinaryTree();
//	BinaryTree(int, Node* = 0, Node* = 0);
//	~BinaryTree();
//	void Insert(int);
//	Node* get_root() const;
//	int height_it() const;
//	int level_max(Node*, int);
//	void print(const Node* ptr) const;
//	void level_print() const;
//	Node* Search(int);
//};
//
//Node* BinaryTree::get_root() const
//{
//	return root;
//}
//
//BinaryTree::BinaryTree()
//{
//	root = 0;
//}
//BinaryTree::~BinaryTree() {}
//void BinaryTree::Insert(int v)
//{
//	if (root != 0)
//	{
//		Insert(v, root);
//	}
//	else
//	{
//		root = new Node;
//		root->value = v;
//		root->depth = 0;
//		root->left = 0;
//		root->right = 0;
//
//	}
//}
//void BinaryTree::Insert(int v, Node* n)
//{
//
//	if (n->value > v)
//	{
//		if (n->left != 0)
//			Insert(v, n->left);
//		else
//		{
//			n->left = new Node;
//			n->left->value = v;
//			n->left->depth = n->depth + 1;
//			n->left->left = 0;
//			n->left->right = 0;
//		}
//	}
//	else
//	{
//
//		if (n->right != 0)
//			Insert(v, n->right);
//		else
//		{
//			n->right = new Node;
//			n->right->value = v;
//			n->right->depth = n->depth + 1;
//			n->right->left = 0;
//			n->right->right = 0;
//		}
//	}
//
//}
//
//Node* BinaryTree::Search(int v, Node* n)
//{
//	if (n != 0)
//	{
//		if (n->value == v)
//			return n;
//		else
//		{
//			if (n->value > v)
//				Search(v, n->left);
//			else
//				Search(v, n->right);
//		}
//	}
//	else return 0;
//}
//
//void BinaryTree::print(const Node* ptr) const
//{
//	if (ptr != nullptr)
//	{
//		print(ptr->left);
//		print(ptr->right);
//		std::cout << ptr->value << ' ';
//	}
//}
///////////////tree height iterative
//int BinaryTree::height_it() const
//{
//	if (root == nullptr)
//		throw "Empty tree";
//	stack<Node*> st;
//	int max = 0;
//	Node* temp = root;
//	st.push(temp);
//	while (!st.empty())
//	{
//		temp = st.top();
//		if (max < temp->depth)
//			max = temp->depth;
//		st.pop();
//		if (temp->right != nullptr)
//			st.push(temp->right);
//		if (temp->left != nullptr)
//			st.push(temp->left);
//	}
//	return max;
//}
//
//void BinaryTree::level_print() const
//{
//	if (root == nullptr)
//		return;
//	Node* temp = root;
//	queue<Node*> Q1, Q2;
//	Q1.push(temp);
//	while (1)
//	{
//		while (!Q1.empty())
//		{
//			temp = Q1.front();
//			std::cout << temp->value << ' ';
//			Q1.pop();
//			if (temp->left != nullptr)
//				Q2.push(temp->left);
//			if (temp->right != nullptr)
//				Q2.push(temp->right);
//		}
//		std::cout << std::endl;
//		if (Q2.empty())
//			return;
//		while (!Q2.empty())
//		{
//			Q1.push(Q2.front());
//			Q2.pop();
//		}
//	}
//}
////////////////////given level's maximum element
//int BinaryTree::level_max(Node* ptr, int lev)
//{
//	if (root == nullptr)
//		throw "Empty tree";
//	Node* temp = ptr;
//	queue<Node*> Q1, Q2;
//	int levelmaxel, count = 0;
//	Q1.push(temp);
//	while (1)
//	{
//		while (!Q1.empty())
//		{
//			temp = Q1.front();
//			if (lev == count)
//			{
//				levelmaxel = temp->value;
//				if (temp->value > levelmaxel)
//					levelmaxel = temp->value;
//			}
//			//std::cout << temp->value << ' ';
//			Q1.pop();
//			if (temp->left != nullptr)
//				Q2.push(temp->left);
//			if (temp->right != nullptr)
//				Q2.push(temp->right);
//		}
//		if (count == lev) break;
//		while (!Q2.empty())
//		{
//			Q1.push(Q2.front());
//			Q2.pop();
//		}
//		++count;
//	}
//	return levelmaxel;
//}
//Node* BinaryTree::Search(int v)
//{
//	return Search(v, root);
//}
//int main()
//{
//	BinaryTree a;
//
//	a.Insert(25);
//	a.Insert(8);
//	a.Insert(30);
//	a.Insert(7);
//	a.Insert(15);
//	a.Insert(27);
//	a.Insert(33);
//	a.Insert(6);
//	a.Insert(14);
//	a.Insert(2);
//
//	cout << "tree a's level traversal" << endl;
//	a.level_print();
//	cout << endl;
//	Node* t = a.get_root();
//	cout << "tree a's postorder traversal" << endl;
//	a.print(t); cout << endl;
//	cout << "2-rd leveli maxel = " << a.level_max(a.get_root(), 2) << endl;
//	cout << "3-rd leveli maxel = " << a.level_max(a.get_root(), 3) << endl;
//	cout << endl;
//	cout << "height = " << a.height_it() << endl;
//	cout << "Element 14's depth = " << a.Search(14)->depth << endl;
//	cout << "Element 2's depth = " << a.Search(2)->depth << endl;
//	system("pause");
//	return 0;
//}
