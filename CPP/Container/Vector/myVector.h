#pragma once
#include <iostream>
using namespace std;

template<typename T>
class myVector
{
	typedef unsigned int UINT;

public:
	class Iterator
	{
	public:
		Iterator() : _ptr(nullptr) {}
		Iterator(T* ptr) : _ptr(ptr) {}
		Iterator(const Iterator& other) : _ptr(other._ptr) {} //복사 생성자

		Iterator& operator=(const Iterator& other) { _ptr = other._ptr; }

		Iterator operator++(int) //후위 단항 연산 표기법
		{
			Iterator temp = *this;
			this->_ptr++;

			return temp;
		}

		//전위 연산
		Iterator operator()
		{
			this->_ptr++;
			return *this;
		}

		bool operator==(const Iterator& other)
		{
			return this->_ptr == other->_ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return !this->operator==(other);
		}

		//간접연산자 오버로딩
		T& operator*()
		{
			return *_ptr;
		}

	private:
		T* _ptr;
	};

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
		for (int i = index; i < _size + 1; i++)
		{
			Swap(temp, _data[i]);
		}
		_size++;
	}

	myVector<T>::Iterator Begin() { return Vector<T>::Iterator(_data); }
	const myVector<T>::Iterator End() { return Vector<T>::Iterator(_data + size); } //끝 부분 + 1된곳을 보여주므로 읽기전용

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

