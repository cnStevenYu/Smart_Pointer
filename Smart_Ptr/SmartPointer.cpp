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
SmartPointer<T>::SmartPointer(SmartPointer<T>& s_ptr)
{
	//reference + 1
	(*s_ptr.count)++;

	this->count = s_ptr.count;
	this->ptr = s_ptr.ptr;
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
		if (*count == 1){
			std::cout << "destroy" << std::endl;
			delete ptr;
			delete count;
		}
		else
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
	(*count)--;
	if (*count == 0)//reference = 0 then delete ptr;
		delete this->ptr;

	(*r_sp.count)++;
	ptr = r_sp.ptr;
	count = r_sp.count;
	return *this;
}


template<class T>
void SmartPointer<T>::reset()
{
	if (*count){
		(*count)--;
		if (*count == 0)
			delete ptr;
	}
	ptr = 0;
}
#endif
