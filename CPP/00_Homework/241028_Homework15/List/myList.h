#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	Node() : data(T()), next(nullptr), prev(nullptr) {}//T() 해당 타입의 기본 생성
	Node(T data) : data(data), next(nullptr), prev(nullptr) {}
	~Node() {}

	T data;
	Node<T>* next;
	Node<T>* prev;
};

template<typename T>
class myList
{
public:
	myList()
	{
		_head = new Node<T>();
		_head->next = _head;
		_head->prev = _head;
		_size = 0;
	}
	~myList()
	{
		if (_size != 0)
		{
			Clear();
		}
		delete _head;
	}

	void Push_back(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		Node<T>* prevNode = _head->prev;
		Node<T>* nextNode = _head;

		newNode->prev = prevNode;
		prevNode->next = newNode;

		newNode->next = nextNode;
		nextNode->prev = newNode;
		_size++;
	}

	void Push_front(const T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		
		newNode->prev = _head;
		newNode->next = _head->next;
		_head->next->prev = newNode;
		_head->next = newNode;
		

		_size++;
	}

	//뒤에걸 지운다.
	void Pop_back()
	{
		DeleteNode(_head->prev);
	}
	void Pop_front() 
	{
		DeleteNode(_head->next);
	}

	Node<T>* findNode(int index)
	{
		if (index > _size)
			return nullptr;
		Node<T>* findNode = _head->next;
		for (int i = 0; i < index; i++)
		{
			findNode = findNode->next;
		}
		return findNode;
	}
	void Insert(Node<T>* before, const T& data)
	{
		Node<T>* newNode = new Node<T>(data);

		newNode->next = before->next;
		newNode->prev = before;

		before->next->prev = newNode;
		before->next = newNode;
		_size++;
	}
	void DeleteNode(Node<T>* node) 
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		_size--;
		delete node;
	}

	const int& Size() { return _size; }

	const int& operator[](int index)
	{
		if (index >= _size) return -1; //찾고싶은 대상이 넘어갔을 경우

		Node<T>* start = _head->next;

		for (int i = 0; i < index; i++)
		{
			start = start->next;
		}

		return start->data;
	}

	void Clear()
	{
		int n = _size;
		for (int i = 0; i < n; i++)
		{
			Pop_back();
		}
	}

	void PrintData()
	{
		Node<T>* n = _head->next;
		cout << "print" << endl;
		while (true)
		{
			if (n == _head)
				return;
			cout << n->prev->data << " - [ " << n->data << " ] - " << n->next->data << endl;
			n = n->next;
		}
	}

private:
	Node<T>* _head;
	int _size;
};

