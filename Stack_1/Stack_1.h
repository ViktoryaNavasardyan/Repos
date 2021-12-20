#pragma once
#include <iostream>
using namespace std;

class Stack
{
private:
	int size;
	int* Array;
	int top;
public:
	Stack(int);
	~Stack();
	void Push(const int&);
	int Pop();
	int GetTop();
	void ClearStack();
	bool Empty() const { return top == -1; }
	bool Full() const { return !(top == -1); }
	void PrintStack();
};

Stack::Stack(int x)
{
	size = x;
	Array = new int[size];
	top = -1;
}

Stack ::~Stack()
{
	delete[] Array;
	//cout << endl<< "Destructor" << endl;
}

void Stack::Push(const int& item)
{
	if (top == size - 1)
		cout << "Stack is full" << endl;
	else
	{
		top++;
		Array[top] = item;
	}
}

int Stack::Pop()
{
	if (top == -1)
	{
		cout << "Stack is empty" << endl;
		return 0;
	}
	int temp;
	temp = Array[top];
	top--;
	return temp;
}

int Stack::GetTop()
{
	if (top == -1)
	{
		cout << "Stack is empty, can't read" << endl;
		return 0;
	}
	return Array[top];
}

void Stack::ClearStack()
{
	while (size)
	{
		top--;
		size--;
	}
}

void Stack:: PrintStack()
{
	if (Empty())
		return;
	int x = GetTop();
	Pop();
	cout << x << ' ';
	PrintStack();
	Push(x);
}