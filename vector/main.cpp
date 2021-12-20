#include <iostream>
using namespace std;
#include "vector.h"

ostream& operator<< (ostream& out, const vector& v);
istream& operator>> (istream& in, vector& v);

int main()
{
	int a[] = { 1,2,3,4,5 };
	vector v1, v2(a, 5);
	cout << "nermucel v1 vectory  " << endl;
	cin >> v1;
	cout << "v1  " << v1 << endl;
	v2.sort();
	cout << "sort of v2   " << v2 << endl;
	cout << "v1 max = " << v1.v_max() << endl;
	vector intersect;
	v1.hatum(v2, intersect);
	cout << "v1 ev v2 hatumy" << endl;
	for (int i = 0; i < intersect.get_size(); i++)
		cout << intersect[i] << " ";
	return 0;
}

ostream& operator<< (ostream& out, const vector& v)
{
	out << "size = " << v.get_size() << "   ";
	for (int i = 0; i < v.get_size(); i++)
		out << v[i] << " ";

	return out;
}

istream& operator>> (istream& in, vector& v)
{
	int size;
	in >> size;
	int* ptr = new int[size];
	for (int i = 0; i < size; i++)
		in >> ptr[i];
	v.set(ptr, size);
	return in;

}