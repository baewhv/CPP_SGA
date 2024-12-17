#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
	Node() : data(0), next(nullptr) {}
	Node(int a) :data(a), next(nullptr) {}
	int data;
	Node* next;
};
class MyStack
{
public:
	MyStack(){
		_top = new Node();
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = _top;
		_top = temp;
	}

	void pop()
	{
		if(_top->next == nullptr) return;
		Node* Temp = _top;
		_top = _top->next;
		delete(Temp);
	}
	int top()
	{
		return _top->data;
	}

	bool empty()
	{
		return _top->next == nullptr ? true: false;
	}

private:
	Node* _top;
};


template<typename T, class Container = vector<int>>
class Stack
{
public:
	void push(T data)
	{
		d.push_back(data);
	}
	T top()
	{
		return d.back();
	}
	void pop()
	{
		d.pop_back();
	}
	bool empty()
	{
		return d.size() == 0;
	}

private:
	Container d;
};

int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	while (true)
	{
		cout << s.top() << endl;
		s.pop();
		if (s.empty() == true)
			break;
	}

}


