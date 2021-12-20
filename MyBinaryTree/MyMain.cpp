#include <iostream>
#include <queue>
#include "MyBTree.h"
using namespace std;
//tpel 90 astijan shrjvac pahpanelov erexaneri dirqery(dzax/aj)
//gagatneri qanaky
//terevneri qanaky
//cari bardzrutyuny mek popoxanaknov
//X tarri handipumneri qanaky

int Number_of_meetings(TreeNode* t,int x)
{
	static int k = 0;
	if (!t) return 0;
	if (t->data == x)
		k++;
	Number_of_meetings(t->left, x);
	Number_of_meetings(t->right, x);

	return k;
}
int main()
{
	TreeNode* x = new TreeNode(90);
	TreeNode* w = new TreeNode(80, x);
	TreeNode* g = new TreeNode(70, NULL, w);
	TreeNode* f = new TreeNode(10);
	TreeNode* e = new TreeNode(50);
	TreeNode* d = new TreeNode(40);
	TreeNode* c = new TreeNode(30, f, g);
	TreeNode* b = new TreeNode(20, d, e);
	TreeNode* a = new TreeNode(10, b, c);
	Print_tree(a, 0);
	cout << endl << "gagatneri qanaky = " << Count_of_nodes(a);
	cout << endl << "terevneri qanaky = " << Count_of_leaves(a);
	cout << endl << "cari bardzrutyuny = " << High(a) << endl;
	int X;
	cout << "nermucel X-y, vory pntrum enq" << endl;
	cin >> X;
	cout << "number of meetings " << X << " = " << Number_of_meetings(a, X) << endl;
	return 0;
}