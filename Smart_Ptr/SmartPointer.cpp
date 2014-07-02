#ifndef _SMARTPOINTER_CPP
#define _SMARTPOINTER_CPP
#include "SmartPointer.h"
template <class T>
SmartPointer<T>::SmartPointer()
{	
	ptr = 0;
	count = 0;
}
template <class T>
SmartPointer<T>::SmartPointer(T* p)
{
	ptr = p;
	count = new int(1);
}
template <class T>
SmartPointer<T>::~SmartPointer()
{
	if (*count > 1){
		(*count)--;
		ptr = 0;
		std::cout << "release:current count is " << *count << std::endl;
	}
	else {
		std::cout << "destroy" << std::endl;
		delete ptr;
		delete count;
	}
}
template <class T>
T* SmartPointer<T>::get()
{
	return ptr;
}
template <class T>
T& SmartPointer<T>::operator*()
{
	return *ptr;
}
template <class T>
T* SmartPointer<T>::operator->()
{
	return ptr;
}
template <class T>
int SmartPointer<T>::use_count()
{
	return *count;
}
template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T>& r_sp)
{
	//*r_sp.count--;
	(*r_sp.count)--;
	(*count)++;
	r_sp.ptr = ptr;
	r_sp.count = count;
	return *this;
}


template<class T>
void SmartPointer<T>::reset()
{
	if (*count){
		(*count)--;
	}
	ptr = 0;
}
#endif
