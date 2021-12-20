#include "vector.h"
#include <assert.h>
#include <algorithm>



using namespace std;

int vector::m_count = 0;

vector::vector(int s)
{
	m_size = s;
	m_ptr = new int[m_size];
	assert(m_ptr != 0);
	for (int i = 0; i < m_size; i++)
		m_ptr[i] = 0;
	m_count++;
}

vector::vector(int* p, int s)
{
	m_size = s;
	m_ptr = new int[m_size];
	assert(m_ptr != 0);
	for (int i = 0; i < m_size; i++)
		m_ptr[i] = p[i];
	m_count++;
}

vector::vector(const vector& v)
{
	m_size = v.get_size();
	m_ptr = new int[m_size];
	assert(m_ptr != 0);
	for (int i = 0; i < m_size; i++)
		//m_ptr[i] = v.m_ptr[i];
		m_ptr[i] = v[i];
	m_count++;
}
vector::~vector()
{
	m_count--;
	delete[] m_ptr;
}

bool vector::operator== (const vector& v) const
{
	if (m_size != v.get_size())
		return false;
	for (int i = 0; i < m_size; i++)
		if (m_ptr[i] != v.m_ptr[i])
			return false;
	return true;
}

bool vector:: operator!= (const vector& v) const
{
	if (m_size != v.get_size())
		return true;
	for (int i = 0; i < m_size; i++)
		if (m_ptr[i] != v[i])
			return true;
	return false;
}

int vector:: operator[] (int i) const
{
	assert(i >= 0 && i < m_size);
	return m_ptr[i];
}

void vector::set(int* p, int size)
{
	m_size = size;
	m_ptr = p;
}

int vector::v_max() const
{
	int m = m_ptr[0];
	for (int i = 1; i < get_size(); i++)
		if (m_ptr[i] > m)
			m = m_ptr[i];
	return m;
}

void vector::sort()
{
	for (int i = 0; i < get_size() / 2; i++)
		swap(m_ptr[i], m_ptr[m_size - i - 1]);
}

void vector::hatum(const vector& in, vector& intersect)
{
	int m = max(get_size(), in.get_size());
	int* p = new int[m];
	int k = 0;
	for (int i = 0; i < get_size(); i++)
	{
		for (int j = 0; j < in.get_size(); j++)
		{
			if (m_ptr[i] == in.m_ptr[j])
			{
				p[k++] = m_ptr[i];
			}
		}
	}
	intersect.set(p, k);
}

const vector& vector:: operator= (const vector& v)
{
	if (*this != v) {
		m_size = v.get_size();
		delete[] m_ptr;
		m_ptr = new int[m_size];
		assert(m_ptr != 0);
		for (int i = 0; i < m_size; i++)
			m_ptr[i] = v[i];
	}
	return *this;
}

int vector::get_size() const
{
	return m_size;
}

bool vector::is_empty() const
{
	return m_size == 0;
}