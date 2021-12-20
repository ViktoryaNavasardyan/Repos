#include <iostream>
#include "list.h"
using namespace std;
/*xndir 14 - Trvac en 2 cucakner. Stanal 3rd cucaky,
vorpes 2 cucakneri kcman ardyunq*/
int main()
{
	//nermucel L1
	List<int> L1;
	int k;
	cout << "Nermucel L1-i elementneri qanaky " << endl;
	cin >> k;
	cout << "Nermucel L1-i amen mi hanguyci int tipi tvyalner@ " << endl;
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		L1.InsertAt(i, x);
	}
	//nermucel L2
	List<int> L2;
	int u;
	cout << "Nermucel L2-i elementneri qanaky " << endl;
	cin >> u;
	cout << "Nermucel L2-i amen mi hanguyci int tipi tvyalnery " << endl;
	for (int i = 0; i < u; i++)
	{
		int x;
		cin >> x;
		L2.InsertAt(i, x);
	}
	//tpel L1y ev L2y
	cout << "L1 = ";
	L1.print();
	cout << "L2 = ";
	L2.print();
	cout << endl;
	
	List<int> L3;
	//cout << "L3 = " << L3.IsEmpty() << endl;
	int L1_length = L1.GetLength();
	int L2_length = L2.GetLength();
	Node<int>* p = L1.GetFirst();
	for (int i = 0; i < L1_length; i++){
		L3.InsertAt(i, L1.GetData(p));
		p = p->link;
	}
	Node<int>* q = L2.GetFirst();
	for (int i = 0; i < L2_length; i++) {
		L3.InsertAt(i + L1_length, L2.GetData(q));
		q = q->link;
	}
	cout << "----------------" << endl;
	cout << "L3 = ";
	L3.print();

	return 0;
}