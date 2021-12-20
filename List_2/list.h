#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* Prev;
	Node* Next;
};

class List
{
private:
	Node *Head;
	int size;
public:
	List();
	~List();
	bool IsEmpty() { return size == 0; }
	int GetLength() { return size; }
	void InsertAfter(Node* p, int item);
	void InsertAt(int n, int item);
	void DeleteAfter(Node* p);
	void DeleteAt(int n);
	int GetData(const Node* p)	{ return p->info; }
	const Node* GetNode(int);
	void print();
	void ClearList();
};

List::List()
{
	size = 0;
	Head = new Node;
	Head->Next = Head;
	Head->Prev = Head;
}

List::~List()                           
{
	ClearList();
	delete Head;
}

void List::InsertAfter(Node* p, int item)
{
	Node* temp = new Node;
	temp->info = item;
	temp->Next = p->Next;
	//if (p->Next != Head) {
		(p->Next)->Prev = temp;
	//}
	p->Next = temp;
	temp->Prev = p;
	size++;
}

void List::InsertAt(int index, int item)
{
	if (index < 0 || index > size) {
		cerr << "out of range" << endl;
		return;
	}
	Node* q = Head;
	for (int i = 0; i < index; i++)
	{			
		q = q->Next;
	}
	InsertAfter(q,item);
}

const Node* List::GetNode(int index)
{
	if (size == 0)
		return NULL;
	if (index < size)
	{
		Node* q = Head->Next;
		for (int i = 0; i < index; i++)
		{
			q = q->Next;
		}
		return q;
	}
	return NULL;
}

void List::DeleteAfter(Node* p)
{
	if (IsEmpty())
	{
		cout << " List is empty " << endl;
		return;
	}
	if (p->Next == Head)
	{
		cout << "No element to delete" << endl;
		return;
	}
	Node* q = p->Next;
	p->Next = q->Next;
	(q->Next)->Prev = p;
	delete q;
	size--;
	return;
}
void List::DeleteAt(int n)
{
	if (n < 0 || n > size)
	{
		cout << "position is out of range" << endl;
	}
	if (size == 0) {
		cout << "no element to delete" << endl;
		return;
	}
	if (size == 1) {
		delete Head->Next;
		Head->Next = Head;
		Head->Prev = Head;
		size = 0;
		return;
	}
	Node* p = Head->Next;
	for (int i = 0; i < n - 1; i++)
		p = p->Next;
	DeleteAfter(p);
}

void List::print()
{
	if (size == 0) {
		cout << "List is empty" << endl;
		return;
	}
	Node* p = Head->Next;
	for (int i = 0; i < size; i++) {
		cout << p->info << " ";
		p = p->Next;
	}
	cout << endl;
}

void List::ClearList()
{
	if (size == 0) {
		return;
	}
	Node* temp = Head->Next->Next;
	Node* current = Head->Next;
	while (size > 0) {
		delete current;
		current = temp;
		temp = temp->Next;
		size--;
	}
	Head->Next = Head;
	Head->Prev = Head;
}