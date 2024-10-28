#pragma once
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

	void Reserve(UINT newCap)
	{
		if (newCap <= _capacity) return;
		int* newData = new int[newCap]; // ���� �Ҵ�

		//copy
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
		//���� �����ִ� ��������
		if (_capacity == _size)
		{
			int newCapacity = _capacity * 1.5f;
			if (newCapacity == _capacity) newCapacity++;

			Reserve(newCapacity);
		}

		_data[_size] = value;
		_size++;
	}

	//�������ٿ����� �����ε� ([])
	int& operator[](UINT index)
	{
		if (index >= _size)
		{
			char* temp = nullptr;
			*temp = 'E';
		}

		return _data[index];
	}

	//index �� ��ġ�� value �� �߰�.
	void Insert(int index, const int& value);


	UINT Size() { return _size; }
	UINT Capacity() { return _capacity; }

private:
	int* _data;
	UINT _size;
	UINT _capacity;
};

