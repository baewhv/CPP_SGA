#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//FIFO

class Queue
{
public: 
	void push(const int& value) { l.push_back(value); }
	void pop() { l.pop_front(); }
	int front() { return l.front(); }
	bool empty() { return l.empty(); }
private:
	list<int> l;
};


int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	while (true)
	{
		cout << q.front() << endl;

		q.pop();

		if (q.empty() == true)
			break;


	}
}