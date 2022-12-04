#include"Array.h"
template<typename T>
Array<T>::Array(int argCount)
{
	if (argCount <= 0)
	{
		capacity = 0;
		data = nullptr;
		return;
	}
	capacity = argCount;
	data = new T[argCount];
}
template<typename T>
T& Array<T>::getSet(const int index)const
{
	if (isValidindex(index))
		return data[index];
	exit(0);
}
template<typename T>
void Array<T>::display()
{
	for (int i = 0; i < capacity; i++)
		cout << data[i] << " ";
	cout << endl;
}
template<typename T>
const T& Array<T>::operator[](const int index) const
{
	if (isValidindex(index))
		return data[index];
	exit(0);
}
template<typename T>
T& Array<T>::operator[](const int index)
{
	if (isValidindex(index))
		return data[index];
	exit(0);
}
template<typename T>
int Array<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
void Array<T>::reSize(const int newCap)
{
	if (newCap <= 0)
	{
		this->~Array();
		return;
	}
	T* ptr = new T[newCap];
	for (int i = 0; i < (newCap < capacity ? newCap : capacity); i++)
		ptr[i] = data[i];
	this->~Array();
	capacity = newCap;
	data = ptr;
	ptr = nullptr;
}
template<typename T>
Array<T>::~Array()
{
	if (data)
		delete[] data;
	capacity = 0;
	data = nullptr;
}
template<typename T>
Array<T>::Array(const Array<T>& ref)
{
	capacity = ref.capacity;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = ref.data[i];
}
template<typename T>
Array<T>& Array<T>::operator =(const Array<T>& ref)
{
	this->~Array();
	data = new T[capacity];
	for (int i = 0; i < capacity; i++)
		data[i] = ref.data[i];
	return *this;
}
template<typename T>
Array<T>::Array(Array<T>&& ref)
{
	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;
	ref.capacity = 0;
}
template<typename T>
Array<T>& Array<T>::operator=(Array<T>&& ref)
{
	this->~Array();
	data = ref.data;
	capacity = ref.capacity;
	ref.data = nullptr;
	ref.capacity = 0;
	return *this;
}