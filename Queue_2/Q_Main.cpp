/*/xndir 5/trvac en Q1 ev Q2 hertery, karucel Q3 herty, vori arajin masum
Q1i tarrern en, isk erkrord masum` Q2i tarrery shrjvac kargov.*/ 

#include <iostream>
#include "Queue_2.h"
using namespace std;

int main()
{
	Queue<int> Q1;
	int size1;
	cout << "enter size 1" << endl;
	cin >> size1;
	cout << "enter members of Q1" << endl;
	for (int i = 0; i < size1; i++){
		int item;
		cin >> item;
		Q1.Push(item);
	}
	Queue<int> Q2;
	int size2;
	cout << "enter size 2" << endl;
	cin >> size2;
	cout << "enter members of Q2" << endl;
	for (int i = 0; i < size2; i++){
		int item;
		cin >> item;
		Q2.Push(item);
	}
	//tpel Q1 ev Q2
	cout << "Q1 = ";
	Q1.PrintQueue();
	cout << endl;
	cout << "Q2 = ";
	Q2.PrintQueue();
	cout << endl;
	//stexcel nor Q3.
	Queue<int> Q3;
	
	while(!Q1.Empty()) {
		int item;
		Q1.GetFirst(item);
		Q3.Push(item);
		Q1.Pop();
	}
	Q2.Reverse();
	while (!Q2.Empty()) {
		int item;
		Q2.GetFirst(item);
		Q3.Push(item);
		Q2.Pop();
	}

	cout << "Q3 = "; 
	Q3.PrintQueue(); 
	cout << endl;

	return 0;
}