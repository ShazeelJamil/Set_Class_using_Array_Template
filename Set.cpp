#include"Set.h"
#include<iostream>
using namespace std;
template<typename T>
bool Set<T>::isFull()const
{
	return (noOfElements == data.getCapacity());
}
template<typename T>
bool Set<T>::isEmpty()const
{
	return noOfElements == 0;
}
template<typename T>
int Set<T>::searchElementPosition(T element)const
{
	int index = 0;
	while (index < noOfElements)
	{
		if (element == data.getSet(index))
			return index;
		index++;
	}
	index = -1;
	return index;
}
template<typename T>
Set<T>::Set(int cap) :data(cap)
{
	noOfElements = 0;
}
template<typename T>
Set<T>::Set(const Set<T>& ref) : data(ref.data)
{
	noOfElements = ref.noOfElements;
}
template<typename T>
Set<T>::Set(Set<T>&& ref) : data(move(ref.data))
{
	noOfElements = ref.noOfElements;
}
template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& ref)
{
	data = ref.data;
	noOfElements = ref.noOfElements;
	return *this;
}
template<typename T>
Set<T>& Set<T>::operator =(const Set<T>&& ref)
{
	data = move(ref.data);
	noOfElements = ref.noOfElements;
	return *this;
}
template<typename T>
void Set<T>::insert(T element)
{
	if (isEmpty())
		reSize(10);
	if (isFull())
		reSize(2 * noOfElements);
	if (searchElementPosition(element) != -1)
		return;
	data.getSet(noOfElements) = element;
	noOfElements++;
}
template<typename T>
void Set<T>::reSize(int newCap)
{
	data.reSize(newCap);
	if (newCap < noOfElements)
		noOfElements = newCap;
}
template<typename T>
void Set<T>::remove(T element)
{
	if (isEmpty())
		return;
	int ind = searchElementPosition(element);
	if (ind == -1)
		return;
	noOfElements--;
	data.getSet(ind) = data.getSet(noOfElements);
}
template<typename T>
void Set<T>::print() const
{
	for (int i = 0; i < noOfElements; i++)
		cout << data.getSet(i) << ' ';
	cout << endl;
}
template<typename T>
int Set<T>::getCardinality()const
{
	return noOfElements;
}
template<typename T>
bool Set<T>::isMember(T value)const
{
	int index = 0;
	while (index < noOfElements)
	{
		if (value == data.getSet(index))
			return true;
		index++;
	}
	return false;
}
template<typename T>
int Set<T>::isSubset(Set s2)const
{
	enum { S2_SUBSET = -1, NO_ONE_SUBSET = 0, CALLING_OBJECT_SUBSET = 1, IMPROPER_SUBSET = 2 };
	if (isEmpty() && s2.isEmpty())
		return IMPROPER_SUBSET;
	if (!isEmpty() && s2.isEmpty())
		return S2_SUBSET;
	if (isEmpty() && !s2.isEmpty())
		return CALLING_OBJECT_SUBSET;
	if (noOfElements < s2.noOfElements)
	{
		int i = 0;
		while ((i < noOfElements) && (s2.isMember(data.getSet(i))))
			i++;
		if (i == noOfElements)
			return CALLING_OBJECT_SUBSET;
		return NO_ONE_SUBSET;
	}
	else if (noOfElements > s2.noOfElements)
	{
		int i = 0;
		while ((i < s2.noOfElements) && (isMember(s2.data.getSet(i))))
			i++;
		if (i == s2.noOfElements)
			return S2_SUBSET;
		return NO_ONE_SUBSET;
	}
	else
	{
		int i = 0;
		while ((i < noOfElements) && (s2.isMember(data.getSet(i))))
			i++;
		return (i == noOfElements ? IMPROPER_SUBSET : NO_ONE_SUBSET);
	}
}
template<typename T>
Set<T> Set<T>::calcUnion(const Set<T>& s2)const
{
	if (s2.isEmpty())
	{
		Set<T> temp(*this);
		return temp;
	}
	else if (isEmpty())
	{
		Set<T> temp{ s2 };
		return temp;
	}
	Set<T> temp{ *this };
	for (int i = 0; i < s2.getCardinality(); i++)
		temp.insert(s2.data.getSet(i));
	return temp;
}
template<typename T>
Set<T> Set<T>::calcIntersection(const Set<T>& s2)const
{
	Set<T> temp;
	if (isEmpty() || s2.isEmpty())
		return temp;
	for (int i = 0; i < noOfElements; i++)
	{
		if (isMember(s2.data.getSet(i)))
			temp.insert(s2.data.getSet(i));
	}
	return temp;
}
template<typename T>
Set<T> Set<T>::calcDifference(const Set<T>& s2)const
{
	if (s2.isEmpty())
	{
		Set<T> temp{ *this };
		return temp;
	}
	Set<T> temp;
	if (isEmpty())
		return temp;
	for (int i = 0; i < noOfElements; i++)
	{
		if (!s2.isMember(data.getSet(i)))
			temp.insert(data.getSet(i));
	}
	return temp;
}
template<typename T>
Set<T> Set<T>::calcSymmetricDifference(const Set<T>& s2)const
{
	Set<T> tunion = calcUnion(s2);
	Set<T> tIntersect = calcIntersection(s2);
	return tunion.calcDifference(tIntersect);
}