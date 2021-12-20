/*erkkap ciklik cucakic heracnel trvac tarry parunakox bolor hangycnery*/

#include "list.h"
#include <iostream>
using namespace std;

//bool Delete_item(List& L, int item)
//{
//	for (int i = 0; i < L.GetLength(); i++) {
//		if (L.GetData(L.GetNode(i)) == item) {
//			cout << "jnjec "<<i+1<<"rd andamy --- " <<L.GetData(L.GetNode(i))<<endl;
//			L.DeleteAt(i);
//			return true;
//		}
//	}
//	return false;
//}

int main()
{
	/*List L2;
	for (int i = 0; i < 1; i++) {
		L2.InsertAt(i, i+10);
	}
	cout << "L2 = "; L2.print();
	L2.DeleteAt(0);
	cout << "L2 = "; L2.print();*/
	List L1;
	int size;
	cout << "nermucel L1i tarreri qanaky" << endl;
	cin >> size;
	cout << "nermucel L1i tarrery" << endl;
	for (int i = 0; i < size; i++) {
		int item;
		cin >> item;
		L1.InsertAt(i, item);
	}
	cout << "L1 = "; L1.print();
	//L1.ClearList();
	//cout << "Clear L1 = "; L1.print();
	int item;
	cout << "nermucel heracvox tivy" << endl;
	cin >> item;
	for (int i = 0; i < L1.GetLength();) {
		if (L1.GetData(L1.GetNode(i)) == item) {
			L1.DeleteAt(i);
		}
		else {
			i++;
		}
	}

	/*while (Delete_item(L1, item)) {
		cout << "L1... = ";
		L1.print();
	}*/
	/*List L2;
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (L1.GetData(L1.GetNode(i)) != item) {
			L2.InsertAt(j, L1.GetData(L1.GetNode(i)));
			j++;
		}
	}
	L1.ClearList();
	cout << "Clear L1 = "; L1.print();
	for (int i = 0; i < j; i++) {
		L1.InsertAt(i, L2.GetData(L2.GetNode(i)));
	}*/
    cout << "----------------"<<endl<<"L1 = "; 
	L1.print();
	cout << endl;
	return 0;
}