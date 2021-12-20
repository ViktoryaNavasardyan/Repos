#pragma once
const int MaxHeap = 1000;
class Heap
{
public:
	Heap() { size = 0; }
	Heap(int* arr, int n) {
		size = n;
		for (int i = 0; i < size; i++)
		{
			items[i] = arr[i];
		}
	}
	bool IsEmpty();
	void Insert(const int& item);
	void Delete(int& root);
	void Print();
	int GetRoot();
private:
	int items[MaxHeap];
	int size;
	void heapRebuild(int root);
};