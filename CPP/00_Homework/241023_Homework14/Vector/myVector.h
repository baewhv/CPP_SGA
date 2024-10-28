#pragma once
#include <iostream>
using namespace std;

template<typename T>
class myVector
{
	typedef unsigned int UINT;
public:
	myVector()
		: _data(nullptr), _size(0), _capacity(0) {}
	~myVector()
	{
		if (_data != nullptr)
			delete[] _data;
		_size = 0;
		_capacity = 0;
	}

	void Reserve(T newCap)
	{
		if (newCap <= _capacity) return;
		int* newData = new int[newCap];

		for (int i = 0; i < _size; i++)
		{
			newData[i] = _data[i];
		}
		delete[] _data;
		_data = newData;
		_capacity = newCap;
	}

	void PushBack(const int& value)
	{
		SizeCheck();

		_data[_size] = value;
		_size++;
	}

	int& operator[](T index)
	{
		if (index >= _size)
		{
			char* temp = nullptr;
			*temp = 'E';
		}

		return _data[index];
	}

	void Insert(int index, const T& value)
	{
		if (index >= _size)
		{
			return;
		}
		SizeCheck();
		T temp = value;
		for(int i = index; i < _size+1; i++)
		{
			Swap(temp, _data[i]);
		}
		_size++;
	}

	UINT Size() { return _size; }
	UINT Capacity() { return _capacity; }

private:
	T* _data;
	UINT _size;
	UINT _capacity;

	void SizeCheck()
	{
		if (_capacity == _size)
		{
			int newCapacity = _capacity * 1.5f;
			if (newCapacity == _capacity) newCapacity++;

			Reserve(newCapacity);
		}
	}

	void Swap(T& lValue, T& rValue)
	{
		T temp = lValue;
		lValue = rValue;
		rValue = temp;
	}
};

