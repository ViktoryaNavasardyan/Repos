#include <iostream>
#include "Heap.h"
using namespace std;
//Ashxatel em burgi nermucman ev jnjelu vra,
//grel em Rebuild, vortex zangvaci anuny, ditarkvox tarri indexy ev zangvaci chapy trvac en vorpes parametr,
//katarel em burgayin kargavorum:
void heapRebuild(int* A, int index, int n);
void heapSort(int* arr, int n);

int main()
{
	int n;
	cin >> n;
	Heap H1;
	int item;
	int* Arr = new int[n];
	//nermucel burgy, ev pahel tarrery zangvacum, hetaqga ogtagorcelu hamar
	for (int i = 0; i < n; i++) {
		cin >> item;
		Arr[i] = item;
		H1.Insert(item);
	}
	//tpel
	cout << "heap = ";
	H1.Print();
	cout << endl;
	//jnjel gagati tarry
	int a;
	H1.Delete(a);
	cout << "jnjac " << endl;
	H1.Print();
	cout << endl;
	//heapRebuildy 3 parametrov
	for (int i = n; i >= 0; i--) {
		heapRebuild(Arr, i, n);
	}
	cout << "heapRebuild" << endl;
	for (int i = 0; i < n; i++) {
		cout << Arr[i] << ' ';
	}
	//burgayin kargavorum
	heapSort(Arr, n);
	cout << endl;
	cout << "Sorted " << endl;
	for (int i = 0; i < n; i++) {
		cout << Arr[i] << ' ';
	}
	cout << endl;
	return 0;

}

void heapRebuild(int* A, int index, int n)
{
	int child = 2 * index + 1;
	if (child < n)
	{
		int rightchild = child + 1;
		if ((rightchild < n) && (A[rightchild] > A[child]))
			child = rightchild;
		if (A[index] < A[child])
		{
			int temp = A[index];
			A[index] = A[child];
			A[child] = temp;
			heapRebuild(A, child, n);
		}
	}
}

void heapSort(int* arr, int n)
{
	for (int index = n - 1; index > 0; index--)
	{
		heapRebuild(arr, index, n);
	}
	int last = n - 1;
	for (int i = 1; i <= n; i++)
	{
		int temp = arr[0];
		arr[0] = arr[last];
		arr[last] = temp;
		last--;
		heapRebuild(arr, 0, last + 1);
	}
}