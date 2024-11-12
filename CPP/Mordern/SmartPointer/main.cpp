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
	SharedPtr(T* ptr) : _block(nullptr), _ptr(ptr) //타입 변환 생성자.
	{
		_block = new RefCountBlock();
		cout << "RefCount : " << _block->refCount << endl;
	}

	//복사했을 때 1 증가.
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
			//참조하고 있는 애가 아무도 없는 경우.
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
	Knight() { cout << "Knight 기본생성자" << endl; }
	Knight(int a) { cout << "Knight 타입변환 생성자" << endl; }
	~Knight() { cout << "Knight 소멸자" << endl; }

	//스마트 포인터는 스마트포인터 형으로만 호출
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

	//스마트 포인터 선언
	shared_ptr<Knight> k = make_shared<Knight>();
	//shared_ptr<Knight> k = shared_ptr<Knight>(new shared_ptr<Knight>());
	shared_ptr<Knight> k2 = make_shared<Knight>(5);
	//[ptr] - 실제 할당된 포인터 변수
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

	//shared_ptr의 순환고리. 소멸하지 않는다.

	return 0;
}