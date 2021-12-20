#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>
using namespace std;

class vector
{
	friend ostream& operator<< (ostream& out, const vector& v);
	friend istream& operator>> (istream& in, vector& v);
public:
	vector(int s = 1); //default
	vector(int* p, int n); //param
	vector(const vector& v); //copy 
	~vector();

public:
	bool operator== (const vector& v) const;
	bool operator!= (const vector& v) const;
	int operator[] (int i) const;
	const vector& operator= (const vector& v);

public:
	int get_size() const;
	bool is_empty() const;
	void set(int* p, int size);
	int v_max() const;
	void sort();
	void hatum(const vector& in, vector& intersect);

private:
	int m_size;
	int* m_ptr;

public:
	static int m_count;
};

#endif