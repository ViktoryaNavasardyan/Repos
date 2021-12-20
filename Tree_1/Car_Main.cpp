#include <iostream>
#include <queue>
#include "Car_1.h"
using namespace std;


int main()
{
	TreeNode* f = new TreeNode(7);
	TreeNode* w = new TreeNode(10);
	TreeNode* d = new TreeNode(4, w, f);
	TreeNode* e = new TreeNode(5);
	TreeNode* g = new TreeNode(6);
	TreeNode* b = new TreeNode(2, d, e);
	TreeNode* c = new TreeNode(3, NULL, g);
	TreeNode* a = new TreeNode(1, b, c);
	TreeNode* o = new TreeNode(8, a);
	cout << "gagatneri qanak" << endl;
	cout << size(a) << endl;
	cout << "Terevneri qanaky: " << size_l(a) << endl;
	cout << "Makardakneri qanaky = " << levels_count(o, 0)<<endl;
	int makardak = levels_count(o, 0);
	for (int i = 0; i < makardak; i++) {
		cout << i << " leveli gagatneri qanaky = ";
		cout << num_level(o, i) << endl;
	}
	cout << "Tpel gagatnery yst makardaki" << endl;
	print(o);
	system("pause");
	return 0;
}
