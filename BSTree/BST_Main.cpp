#include <iostream>
#include "BSTree.h"
using namespace std;

/*nermucel zangvac vory kpahvi carum, stugel cary lriv e te voch rekursiv ev iterativ dzeverov,
poxarinel cari amen gagat ayd gagatov cnvox entacari terevneri qanakov ev bardzrutyamb*/

int main()
{
	//nermucel
	int count;
	cout << "enter count" << endl;
	cin >> count;
	cout << "enter members " << endl;
	int* arr = new int[count];
	for (int i = 0; i < count; i++) {
		cin >> arr[i];
	}
	BSTree tree(arr, count);
	Node* root_tree = tree.GetRoot();
	//tpel
	tree.Print_tree90(root_tree, 0);
	cout << "gagatneri qanaky ----" << tree.GetFullCount(root_tree) << endl;
	//Is the tree full or not in iterativ and recursiv ways
	if (tree.IsFull())
		cout << "tree is full iterativ way" << endl;
	else
		cout << "tree is not full iterativ way" << endl;

	if (tree.Is_Full_Rec(root_tree))
		cout << "tree is full recursiv way" << endl;
	else
		cout << "tree is not full recursiv way" << endl;	
	//poxarinel
	cout << "amen gagat poxarinel irenov cnvac entacari terevneri qanakov" << endl;
	tree.Tree_Leaf(root_tree);
	tree.Print_tree90(root_tree, 0);
	cout << "amen gagat poxarinel irenov cnvac entacari bardzrutyamb" << endl;
	tree.Tree_High(root_tree);
	tree.Print_tree90(root_tree, 0);

	return 0;
} 