#pragma once
#include<iostream>
using namespace std;

struct Node
{
	Node(int data) : data(data), next(nullptr), prev(nullptr) {}
	~Node() {}

	int data;
	Node* next;
	Node* prev;
};

class myList
{
public:
	myList()
	{
		_head = new Node(-1);
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

	void Push_back(const int& data)
	{
		Node* newNode = new Node(data);

		Node* prevNode = _head->prev;
		Node* nextNode = _head;

		newNode->prev = prevNode;
		prevNode->next = newNode;

		newNode->next = nextNode;
		nextNode->prev = newNode;
		_size++;
	}

	void Push_front(const int& data)
	{
		Node* newNode = new Node(data);
		
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

	Node* findNode(int index)
	{
		if (index > _size)
			return nullptr;
		Node* findNode = _head->next;
		for (int i = 0; i < index; i++)
		{
			findNode = findNode->next;
		}
		return findNode;
	}
	void Insert(Node* before, const int& data)
	{
		Node* newNode = new Node(data);

		newNode->next = before->next;
		newNode->prev = before;

		before->next->prev = newNode;
		before->next = newNode;
		_size++;
	}
	void DeleteNode(Node* node) 
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

		Node* start = _head->next;

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
		Node* n = _head->next;
		cout << "print"<< endl;
		while (true)
		{
			if (n == _head)
				return;
			cout << n->prev->data << " - [ " << n->data << " ] - " << n->next->data << endl;
			n = n->next;
		}
	}

private:
	Node* _head;
	int _size;
};

