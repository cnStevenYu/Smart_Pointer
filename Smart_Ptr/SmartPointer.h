#ifndef _SMARTPOINTER_H
#define _SMARTPOINTER_H
#include <iostream>
template <class T>
class SmartPointer{
public:
	SmartPointer();
	SmartPointer(T *);
	SmartPointer(SmartPointer<T>&);
	~SmartPointer();
	T* get();
	int use_count();
	void reset();
	T& operator*();
	T* operator->();
	SmartPointer<T>& operator=(SmartPointer<T> &);

private:
	T *ptr;
	int *count;
};
#include "SmartPointer.cpp"
#endif