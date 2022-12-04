#include<iostream>
#include"Set.h"
using namespace std;
int main()
{
	Array<int> a(10);
	for (int i = 0; i < a.getCapacity(); i++)
	{
		a[i] = i + 10;
	}
	a.display();
	for (int i = 0; i < a.getCapacity(); i++)
	{
		a[i] = i + 10;
	}
	cout << a.getCapacity();
	a.display();

	//Set<int> s;
	//for (int i = 1; i <= 10; i++)
	//	s.insert(i);
	////for (int i = 5; i < 15; i++)
	////	s1.insert(i);
	//s.print();
	//s1.print();
	//s.calcDifference(s1).print();
	//s.calcUnion(s1).print();
	//s.calcIntersection(s1).print();
	//s.calcSymmetricDifference(s1).print();
	return 0;
}