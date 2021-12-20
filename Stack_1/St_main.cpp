/*trvac en S1 ev S2 stackery, karucel S3y, vori hatakum S1i tarrern en
isk verevum dasavorvac en S2i tarrery` shrjvac kargov.*/
#include <iostream>
#include "Stack_1.h"
using namespace std;

int main()
{
	int size1;
	cout << "nermucel size1 y" << endl;
	cin >> size1;
	Stack S1(size1);
	cout << "nermucel arajin pahunaki tarrery" << endl;
	for (int i = 0; i < size1; i++) {
		int x;
		cin >> x;
		S1.Push(x);
	}
	cout << "S1 = "; S1.PrintStack();
	cout << endl << "---------------" << endl;
	int size2;
	cout << "nermucel size2 y" << endl;
	cin >> size2;
	Stack S2(size2);
	cout << "nermucel arajin pahunaki tarrery" << endl;
	for (int i = 0; i < size2; i++) {
		int x;
		cin >> x;
		S2.Push(x);
	}
	cout << "S2 = "; S2.PrintStack(); cout << endl;
	cout << "--------------" << endl;
	//stexcenq ognox stack
	Stack S(size1);
	for (int i = 0; i < size1; i++){
		S.Push(S1.Pop());
	}
	Stack S3(size1 + size2);
	for (int i = 0; i < size1; i++) {
		S3.Push(S.Pop());
	}
	for (int i = 0; i < size2; i++) {
		S3.Push(S2.Pop());
	}
	cout << "S3 = "; S3.PrintStack(); cout << endl;

	return 0;
}