#include <iostream>
#include <math.h> 
#include <queue>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int d, TreeNode* l = NULL, TreeNode* r = NULL)
	{
		data = d;
		left = l;
		right = r;
	}
	TreeNode() {
		/*data = 0;
		left = NULL;
		right = NULL;*/
	}
};

void CinTree(TreeNode*& q, int n) {//iterativ dzevov nermucelu funkcia
	if (!q) {
		delete q;
		q = new TreeNode;
	}
	TreeNode** w = new TreeNode * [n];
	w[0] = q;
	int t = 0;
	int j = 1;
	int x;
	for (int i = 0; i < n; i++) {
		if (!(i % 2)) {
			++t;
		}
		cin >> w[i]->data;
		w[i]->left = new TreeNode;
		w[i]->right = new TreeNode;
		if (!(i % 2)) {
			w[i + 1] = w[t - 1]->left;
			continue;
		}

		w[i + 1] = w[t - 1]->right;
	}

	if (!(n % 2))
		w[n - t - 1]->right = NULL;
	for (int j = n - t; j < n; j++) {
		w[j]->left = NULL;
		w[j]->right = NULL;
	}

}
// gagatneri qanaky
int size(TreeNode* q) {
	if (!q)
		return 0;

	return 1 + size(q->left) + size(q->right);

}
//terevneri qanaky
int s_leaf(TreeNode* t) {
	if (!t) return 0;
	if (!(t->left) && !(t->right)) return 1;
	return s_leaf(t->left) +
		s_leaf(t->right);
}
//level-um gagatneri qanaky
int level_c(TreeNode* q, int l) {
	if (!q) return 0;
	if (l == 0) return 1;
	return level_c(q->left, l - 1) + level_c(q->right, l - 1);
}
int heighT(TreeNode* f) {
	if (!f) return -1;
	return max((heighT(f->left)), (heighT(f->right))) + 1;

}
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
//funkcia vorov nermucum enq cary
int main() {
	TreeNode* e = new TreeNode;
	int n;
	cin >> n;
	CinTree(e, n);

	print(e);
	cout << s_leaf(e) << " ";
}