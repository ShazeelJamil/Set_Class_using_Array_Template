#ifndef SET_H
#define SET_H
#include"Array.h"
template<typename T>
class Set
{
	Array<T> data;
	int noOfElements;
	bool isFull()const;
	bool isEmpty()const;
	int searchElementPosition(T element)const;
public:
	Set(int cap = 0);
	Set(const Set<T>&);
	Set(Set<T>&&);
	Set<T>& operator =(const Set<T>&);
	Set<T>& operator = (const Set<T>&&);
	void insert(T element);
	void reSize(int);
	void remove(T);
	void print() const;
	int getCardinality()const;
	bool isMember(T)const;
	int isSubset(Set<T>)const;
	Set<T> calcUnion(const Set<T>&)const;
	Set<T> calcIntersection(const Set<T>& s2)const;
	Set<T> calcDifference(const Set<T>& s2)const;
	Set<T> calcSymmetricDifference(const Set<T>& s2)const;
};
#endif // !ARRAY_H

