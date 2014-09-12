#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class IndexOutofBounds
{
public:
    IndexOutofBounds(int);
    ~IndexOutofBounds();
    void printErr();
private:
    int Index;
};

template <class T>
class Vector {
public:
	Vector();
	Vector(int size);
	Vector(const Vector& r);	
	virtual ~Vector();
	T& operator[](int index)throw(IndexOutofBounds);

	int size(){return m_nSize;}
	int inflate(int addSize);	
private:
	T *m_pElements;
	int m_nSize;
};
template<class T>
Vector<T>::Vector():m_nSize(0),m_pElements(NULL){}

template<class T>
Vector<T>::Vector(int size):m_nSize(size),m_pElements(NULL)
{
	m_pElements = new T[size];
}

template <class T>
Vector<T>::Vector(const Vector& V):m_nSize(V.m_nSize)
{
	int i;
	m_pElements = NULL;
	//m_nSize = V.m_nSize;
	m_pElements = new T[m_nSize];
    for (i = 0; i < m_nSize; i++)
        m_pElements[i] = V.m_pElements[i];
}
template <class T>
Vector<T>::~Vector()
{
	delete[] m_pElements;
}
template <class T>
T& Vector<T>::operator[](int Index)throw(IndexOutofBounds)
{
    if (Index < m_nSize && Index >= 0)
  		return m_pElements[Index];
	else
		throw IndexOutofBounds(Index);
}

template <class T>
int Vector<T>::inflate(int addSize)
{
    T *p = new T[m_nSize + addSize];
    for (int i = 0; i < m_nSize; i++)
        p[i] = m_pElements[i];
    delete[] m_pElements;
    m_pElements = p;
    m_nSize += addSize;
    return m_nSize;
}

#endif // VECTOR_H
