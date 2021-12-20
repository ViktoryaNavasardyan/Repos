#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T info;
	Node <T>* link;
};

template <class T>
class List
{
private:
	Node<T>* first;
	int size;
public:
	List();
	List(const List&);
	~ List();
	bool IsEmpty() const	{return size == 0; }
	int GetLength() const	{return size; }
	Node<T>* GetFirst() const	{ return first; }
	void InsertAfter(Node<T>* p, T item);
	void InsertAt(int n, T item);
	void DeleteAfter(Node<T>*p);
	void DeleteAt(int n);  
	T& GetData(Node<T>* p)	{ return p->info; }
	Node<T>* GetNode(int n);
	void print();
};
#endif

template <class T>
List <T>::List() : size(0), first(NULL)
{
}

template <class T>
List <T>::List(const List& List1) {
	Node<T>* p = new Node<T>;
	Node<T>* p1 = List1.first;
	GetData(p) = GetData(p1);
	first = p;
	first->link = NULL;
	for (int i = 0; i < List1.GetLenght() - 1; i++) {
		p1 = p1->link;
		InsertAfter(p, GetData(p1));
		p = p->link;
	}
	size = List1.size;
}

template <class T>
List <T>::~List()
{
	if (first) {
		while (first->link)
			DeleteAfter(first);
		delete first;
		first = 0;
	}
	size = 0;
}

template <class T>
void List <T>::InsertAfter(Node<T>* p, T item)
{
	Node<T>* q = new Node<T>;
	q->info = item;
	q->link = p->link;
	p->link = q;
	size++;
}

template <class T>
void List <T>::InsertAt(int n, T item)
{
	if (n<0 || n> GetLength())
		throw "out";
	if (n == 0) {
		Node<T>* q = new Node<T>;
		q->info = item;
		q->link = first;
		first = q;
		size++;
		return;
	}
	Node<T>* p = first;
	for (int i = 0; i < n - 1; i++)
		p = p->link;
	InsertAfter(p, item);
}

template<class T>
void List<T>::DeleteAfter(Node<T>* p)
{
	if (IsEmpty())
		cout << "List is empty" << endl;
	if (p->link == NULL)
		cout << "No element to delete" << endl;
	Node<T>* q = p->link;
	p->link = q->link;
	delete q;
	size--;
	return;
}

template<class T>
void List<T>::DeleteAt(int n)
{
	if (n<0 || n>GetLength())
		cerr << "n is out of range" << endl;
	if (n == 0 && GetLength() != 0) {
		Node<T>* q = first;
		first = first->link;
		delete q;
		size--;
		return;
	}
	Node<T>* p = first;
	for (int i = 0; i < n - 1; i++)
		p = p->link;
	DeleteAfter(p);
	return;
}


template<class T>
Node<T>* List<T>::GetNode(int m)
{
	if (size == 0)
		return NULL;
	if (m < size)
	{
		Node<T>* q = first;
		for (int i = 0; i < m; i++)
		{
			q = q->link;
		}
		return q;
	}
	return NULL;
}

template<class T>
void List<T>::print()
{
	for (Node<T>* p = first; p; p = p->link)
		cout << p->info << ' ';
	cout << endl;
}