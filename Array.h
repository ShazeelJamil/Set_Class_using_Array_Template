#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
template<typename T>
class Array
{
	T* data;
	int capacity;
	int isValidindex(int index) const
	{
		return (index >= 0 && index < capacity);
	}
public:
	Array(int argCount=0);
	Array(const Array<T>& ref);//Copy constructor
	Array<T>& operator =(const Array<T>& ref);//Copy Assignment
	Array(Array<T>&& ref);//Move constructor
	Array<T>& operator=(Array<T> && ref);//Move Assignment
	T& getSet(const int index)const;
	void display();
	const T& operator[](const int index) const;
	T& operator[](const int index);
	int getCapacity() const;
	void reSize(const int newCap);
	~Array();
};
#endif // !ARRAY_H