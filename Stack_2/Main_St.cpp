/*xndir7/ Trvac en S1 ev S2. Karucel S3 pahunaky
vori mej mekumej drvum en S1 ev S2 pahunakneri tarrery, 
ev verjum avelacvum en chdatarkvac pahunaki tarrery*/

#include <iostream>
#include "Stack_2.h"
using namespace std;

int main() 
{
	Stack<int> S1;
	Stack<char> S2;
	int size1;
	cout << "nermucel size 1" << endl;
	cin >> size1;
	cout << "nermucel S1 i tarrery" << endl;
	for (int i = 0; i < size1; i++) {
		int item1;
		cin >> item1;
		S1.Push(item1);
	}
	//S2.Enter();
	int size2;
	cout << "nermucel size 2" << endl;
	cin >> size2;
	cout << "nermucel S2 i tarrery" << endl;
	for (int i = 0; i < size2; i++) {
		char item2;
		cin >> item2;
		S2.Push(item2);
	}
	cout << "S1 = "; S1.PrintStack(); cout << endl;
	cout << "S2 = "; S2.PrintStack(); cout << endl;
	cout << "---------------------------------" << endl;
	int maxsize;
	maxsize = (size1 < size2) ? size2 : size1;
	for (int i = 0; i < maxsize; i++) {
		if (!S1.Empty()) {
			cout << S1.GetTop() << " ";
			S1.Pop();
		}
		if (!S2.Empty()) {
			cout << S2.GetTop() << " ";
			S2.Pop();
		}
	}
	cout << endl;
	return 0;
}