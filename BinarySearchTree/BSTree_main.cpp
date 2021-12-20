#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include "BSTree.h"
using namespace std;
/*1․սիմետրիկ շրջանցում իտերատիվ, 2․ուղիղ շրջանցում իտերատիվ 3․հակադարձ շրջանցում իտերատիվ, 4․լայնակի շրջանցում իտերատիվ ,
5․ուղիղ շրջանցում, տարրերը բազմապատկելով 10-ով, ռեկուրսիվ,
6․գտնելներմուծված x-ի հասցեն և x-ի հասցեում պարունակող տարրը, եթե այն գոյություն ունի, 
հակառակ դեպքում արտածել համապատասխան գրառում,
7․ներմուծել զանգված, որը կպահվի ծառի մեջ*/

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
	BinSTree a;
	a.Insert(10);
	a.Insert(20);
	a.Insert(8);
	a.Insert(6);
	a.Insert(25);
	a.Insert(12);
	a.Insert(7);
	a.Insert(11);
	a.Insert(14);
	TreeNode* s=a.Getroot();
	a.Print_tree90(s, 0);
	cout << u8"սիմետրիկ շրջանցում՝ " << endl;
	a.InOrder();
	cout << endl;
	cout << u8"ուղիղ շրջանցում՝ " << endl;
	a.PreOrder();
	cout << endl;
	cout << u8"հակադարձ շրջանցում՝ " << endl;
	a.PostOrder();
	cout << endl;
	cout << u8"լայնակի շրջանցում՝ " << endl;
	a.Transverse();
	cout << endl;

	//տպել ուղիղ շրջանցումով, տարրերը բազմապատկելով 10-ով
	cout << u8"visit1 ֆունկցիայի արդյունքը՝ " << endl;
	a.preOrder(s,visit1);
	cout << endl;

	/*գտնելներմուծված x-ի հասցեն և x-ի հասցեում պարունակող տարրը,
	եթե այն գոյություն ունի, հակառակ դեպքում արտածել համապատասխան գրառում*/
	int x;
	cout << u8"ներուծել փնտրվող x-ը " << endl;
	cin >> x;
	TreeNode* t = a.Search(x);
	int value;
	if (t)
	{
		a.GetInfo(t, value);
		cout << "Search(" << x << ") = " << t << endl;
		cout << u8"x-ի հասցեում պարունակող տարրի info = "<< value << endl;
	}
	else {
		cout << "No element found" << endl;
	}
	
	cout << "......................................." << endl;
	//ներմուծել զանգված, որը կպահվի ծառի մեջ
	int count;
	cout << u8"ներմուծել քանակը " << endl;
	cin >> count;
	cout << u8"ներմուծել տարրերը " << endl;
	int* arr = new int [count];
	for (int i = 0; i < count; i++) {
			cin >> arr[i];
	}
	BinSTree car(arr, count);
	TreeNode* root = car.Getroot();
	//տպել նոր ստացված ծառը
	cout << "New tree " << endl;
	car.Print_tree90(root,0);
	
	
	return 0;
}