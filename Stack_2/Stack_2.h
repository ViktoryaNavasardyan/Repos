#ifndef Stack_LIST_H
#define Stack_LIST_H
#include <cassert>
#include <iostream>
using namespace std;

template<class T>
struct Node {
	T info;	             
	Node <T>* link;       
	Node(T& elem, Node<T>* ptr = NULL) :	
		info(elem), link(ptr) {}	
};

template<class T>
class Stack			
{
private:
	Node<T>* Top;	
	int Size;	
public:
	Stack();
	~Stack();
	void Push(T& Value);
	void Pop();
	T& GetTop() { return Top->info; }
	bool Empty(){ return Size == 0; }
	int GetSize() { return Size; }
	void Clear();
	void Enter();
	void PrintStack();
};

template<class T>
Stack<T>::Stack() {
	Size = 0;
	Top = NULL;
}

template<class T>
Stack<T>::~Stack() {
	Clear();
}

template<class T>
void Stack<T>::Push(T& value) {
	Top = new Node<T>(value, Top);
	Size++;
}

template<class T>
void Stack<T>::Pop() {
	assert(!Empty());
	Node<T>* ptr = Top->link;
	delete Top;
	Top = ptr;
	Size--;
}

template<class T>
void Stack<T>::Clear() {
	while (Top) {
		Node<T>* ptr = Top->link;
		delete Top;
		Top = ptr;
	}
	Size = 0;
}

template<class T>
void Stack<T>::Enter()
{
	int size;
	cout << "nermucel size" << endl;
	cin >> size;
	cout << "nermucel S i tarrery" << endl;
	for (int i = 0; i < size; i++) {
		T item;
		cin >> item;
		Push(item);
	}
}

template<class T>
void Stack<T>::PrintStack()
{
	if (Empty())
			return;
	T x = GetTop();
	Pop();
	cout << x << ' ';
	PrintStack();
	Push(x);
	
}
#endif
