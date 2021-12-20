#include <iostream>
#include "Heap.h"
using namespace std;

bool Heap::IsEmpty()
{
	return size == 0;
}

void Heap::Insert(const int& item)
{
	if (size >= MaxHeap)
		cout << "Heap is full" << endl;
	else
	{
		items[size] = item;
		int place = size;
		int parent = (place - 1) / 2;
		while ((parent >= 0) && (items[place] > items[parent]))
		{
			int temp = items[parent];
			items[parent] = items[place];
			items[place] = temp;
			place = parent;
			parent = (place - 1) / 2;
		}
		size++;

	}
}

void Heap::Delete(int& root)
{
	if (IsEmpty())
		cout << "Empty heap" << endl;
	else
	{
		root = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
}

void Heap::heapRebuild(int root)
{
	int child = 2 * root + 1;
	if (child < size)
	{
		int rightchild = child + 1;
		if ((rightchild < size) && (items[rightchild] > items[child]))
			child = rightchild;
		if (items[root] < items[child])
		{
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;
			heapRebuild(child);
		}
	}
}

void Heap::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << items[i] << " ";
	}
}

int Heap::GetRoot()
{
	return items[0];
}