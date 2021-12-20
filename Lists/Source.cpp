

#include <iostream>
using namespace std;

template <class T>
struct Node {
	T info;
	Node <T>* link;
};
template <class T>
class List {
private:
	Node<T>* first;
	int size;
public:
	List();
	List(const List&);
	// ~ List();
	bool IsEmpty() const;
	int GetLenght() const;
	Node<T>* GetFirst() const;
	void InsertAfter(Node<T>* p, T item);
	void InsertAt(int n, T item);
	// void DeleteAfter(Node<T>*p);
	// void DeleteAt(int n);  
	T& GetData(Node<T>* p);
	void print();
};
template <class T>
List <T>::List() : size(0), first(NULL) {
}
template <class T>
List <T>::List(const List& aList) {
	Node<T>* p = new Node<T>, * p1 = aList.first;
	GetData(p) = GetData(p1);
	first = p; first->link = NULL;
	for (int i = 0; i < aList.GetLenght() - 1; i++) {
		p1 = p1->link;
		InsertAfter(p, GetData(p1));
		p = p->link;
	}
	size = aList.size;
}
/*template <class T>
List <T>::~List() {
if (first){
while
(first->link)
DeleteAfter(first);
delete first;
first=0;
}
size=0;
}*/

template <class T>
bool List <T>::IsEmpty() const {
	return size == 0;
}
template <class T>
int List <T>::GetLenght() const {
	return size;
}
template <class T>
Node<T>* List <T>::GetFirst() const {
	return first;
}

template <class T>
void List <T>::InsertAfter(Node<T>* p, T item) {
	Node<T>* q = new Node<T>;
	q->info = item;
	q->link = p->link;
	p->link = q;
	size++;
}
template <class T>
void List <T>::InsertAt(int n, T item) {
	if (n<0 || n> GetLenght())
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

/* DeleteAfter(Node<T>*p);
void DeleteAt(int n);*/
template <class T>
T& List <T>::GetData(Node<T>* p) {
	return p->info;
}

template<class T>
void List<T>::print()
{
	for (Node<T>* p = first; p; p = p->link)
		cout << p->info << ' ';
	cout << endl;
}

int main() {
	try {
		const int n = 10;
		List <double> L1;
		double a[n]; int i;
		for (i = 0; i < n; i++) {
			cin >> a[i];
			cout << a[i];
			L1.InsertAt(i, a[i]);

		}

		Node <double>* p;
		Node <double>* p1;
		List <double> L2 = L1;

		cout << "%%%%%%%%%%%%%%%";
		p = L1.GetFirst();
		cout << p << "0000000000000000000";
		p1 = L2.GetFirst();

		cout << "-----------------";
		cout << L1.GetFirst();
		cout << "******************" << endl;
		cout << L2.GetFirst();

		double S = 0, S1 = 0;
		for (i = 0; i < L1.GetLenght(); i++) {
			S = S + L1.GetData(p);
			S1 = S1 + L2.GetData(p1);
			cout << L1.GetData(p) << "  ";
			cout << L2.GetData(p1) << "  ";
			p = p->link; p1 = p1->link;
		}   cout << S << " ////////// ";
		cout << "*********************************";
		cout << S1 << " ////////// ";
		L1.print();
	}

	catch (char* str) {
		cout << str << endl;
	}

	system("pause");
	return 0;
}