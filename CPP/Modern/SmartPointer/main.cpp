#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct RefCountBlock
{
	int refCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr) : _block(nullptr), _ptr(ptr) //Ÿ�� ��ȯ ������.
	{
		_block = new RefCountBlock();
		cout << "RefCount : " << _block->refCount << endl;
	}

	//�������� �� 1 ����.
	SharedPtr(const SharedPtr<T>& other)
		:_ptr(other._ptr)
		, _block(other._block)
	{
		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}
	}

	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->refCount--;
			cout << "RefCount : " << _block->refCount << endl;
			//�����ϰ� �ִ� �ְ� �ƹ��� ���� ���.
			if (_block->refCount <= 0)
			{
				delete _block;
				delete _ptr;
				_ptr = nullptr;
			}
		}
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& other)
	{
		_ptr = other._ptr;
		_block = other._block;
		if (_ptr != nullptr)
		{
			_block->refCount++;
			cout << "RefCount : " << _block->refCount << endl;
		}

		return *this;
	}

	T* operator->()
	{
		if (_ptr != nullptr)
			return _ptr;

		return nullptr;
	}

private:
	RefCountBlock* _block;
	T* _ptr;
};

class Knight
{
public:
	Knight() { cout << "Knight �⺻������" << endl; }
	Knight(int a) { cout << "Knight Ÿ�Ժ�ȯ ������" << endl; }
	~Knight() { cout << "Knight �Ҹ���" << endl; }

	//����Ʈ �����ʹ� ����Ʈ������ �����θ� ȣ��
	void Attack()
	{
		target->_hp -= _attack;
		if (wTarget.expired() == false)
		{
			wTarget.lock()->_hp -= _attack;
		}
	}

	shared_ptr<Knight> target = nullptr;
	weak_ptr<Knight> wTarget;


	int _hp = 0;
	int _attack = 0;
};


int main()
{
	//shared_ptr
	//weak_ptr
	//unique_ptr

	//����Ʈ ������ ����
	shared_ptr<Knight> k = make_shared<Knight>();
	//shared_ptr<Knight> k = shared_ptr<Knight>(new shared_ptr<Knight>());
	shared_ptr<Knight> k2 = make_shared<Knight>(5);
	//[ptr] - ���� �Ҵ�� ������ ����
	//[control block] 
	k->_hp = 100;
	k->_attack = 10;

	k2->_hp = 50;
	k2->_attack = 5;

	k->target = k2;
	k2->target = k;

	k->Attack();
	k2->Attack();

	//SharedPtr<Knight> p1 = SharedPtr<Knight>(new Knight());
	//SharedPtr<Knight> p2 = SharedPtr<Knight>(new Knight());
	//p1->target = p2;
	//p2->target = p1;

	//p1->Attack();
	//p2->Attack();

	//shared_ptr�� ��ȯ��. �Ҹ����� �ʴ´�.

	return 0;
}