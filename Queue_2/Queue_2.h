#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template<class T>
struct Node {
	T info;
	Node <T>* link;
};

template<class T>
class Queue
{
private:
	Node<T>* first;
	Node<T>* last;
	Node<T> head;
public:
	Queue(): first(&head), last(&head) {}
	~Queue();
	void Push(T item);
	void Pop();
	void GetFirst(T& item);
	bool Empty()const { return last == &head; }
	void Clear();
	void PrintQueue();
	void Reverse();
};

template<class T>
Queue<T>::~Queue() 
{
	Clear();
}

template<class T>
void Queue<T>::Reverse()
{
	if (Empty())
		return;
	int x;
	GetFirst(x);
	Pop();
	Reverse();
	Push(x);
}

template<class T>
void Queue<T>::Push(T item) {
	Node<T>* p = new Node<T>;
	if (!p)
		throw "Overflow in heap";
	p->info = item;
	p->link = 0;
	last->link = p;
	last = p;
}

template<class T>
void Queue<T>::Pop() {
	assert(!Empty());
	Node<T>* p = head.link;
	head.link = p->link;
	delete p;
	if (head.link == 0) {
		last = &head;
		head.link = NULL;
	}
}

template<class T>
void Queue<T>::Clear() {
	Node<T>* p;
	if (first != last) {
		p = first->link;
		while (p) {
			first->link = p->link;
			delete p;
			p = first->link;
		}
		last = first;
	}
}

template<class T>
void Queue<T>::GetFirst(T& item) 
{
	if (Empty())
		cout << "Empty Queue" << endl;
	item = head.link->info;
	return;
}

template<class T>
void Queue<T>::PrintQueue()
{
	if (Empty())
		return;
	Queue<T> Q;
	T x;
	while (!Empty()) {
		GetFirst(x);
		cout << x << " ";
		Q.Push(x);
		Pop();
	}
	//copy back to the original Queue
	while (!Q.Empty()) {
		T item;
		Q.GetFirst(item);
		Push(item);
		Q.Pop();
	}
}
