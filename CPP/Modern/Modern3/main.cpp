#include <iostream>
#include <vector>

using namespace std;

// shift : 이동 = move

// lvalue : 수정할 수 있는 변수 (참조)
// rvalue : lvalue가 아닌 수. 식을 수정할 수 없는 수(상수) = 임시 값, 임시 객체.

// 우측 값 참조란: lValue를 rValue로 변경.
// -> lValue는 껍데기만 남긴다.

class Pet
{

};


class Player
{
public:
	Player() : _pet(new Pet()) { cout << "기본 생성자" << endl; }
	Player(int hp) : _hp(hp), _pet(new Pet()) { cout << "타입 변환 생성자" << endl; }
	Player(const Player& other) : _hp(other._hp), _pet(new Pet(*other._pet)) { cout << "복사 생성자" << endl; }


	//이동 생성자
	//other 의 모든 것을 여기에 옮기고 other는 껍데기만 남긴다.
	//어디에 쓰일까?
	//크기가 큰 클래스의 내용물을 이동하려 할 때.
	//이를 복사 생성 후 지우려면 메모리가 그만큼 필요. & 초기화가 또 일어남.

	Player(Player&& other) noexcept
	{
		cout << "이동 생성자" << endl;
		_hp = other._hp;
		_pet = other._pet;

		other._pet = nullptr;
	}


	~Player() 
	{
		if(_pet != nullptr)
			delete _pet; 
		cout << "소멸자 호출" << endl;
	}

	Player& operator=(const Player& other)
	{
		_hp = other._hp;
		_pet = other._pet;

		return *this;
	}
	
	int _hp = 0;
	Pet* _pet;
	
};

//Call by Value
//1. 원본에 영향이 가지 않는다.

void Func(Player p) 
{
	p = Player(5);

	Player pp = Player(5); //타입변환생성자
}

//Call by Address
//1. 복사비용이 적다.
//2. 원본에 접근 가능하다.
//3. 쓰기 어렵다.
	//허상 포인터에 접근하고있는지 등.
void Func(Player* p)
{
	
}

// Call by Ref
// 1. 복사 비용이 적다.
// 2. 원본 접근이 가능하다.
// 3. 
// 4. 없는 값(nullptr) 혹은 임시 객체를 넘길 수 없다.
void FuncRef(Player& p)
{

}

// Call by Rv Ref
// 1. 복사비용이 적게 든다.
// 2. 원본이 접근 가능하다.
// 3. 쓰기 쉽다.
// 4. 임시 객체 또한 넘길 수 있다.
void FuncRefRef(Player&& p)
{
	cout << "우측값 참조 전달" << endl;
}



int main()
{
	// 10 = 5; 10 -> 수정할 수 없는 값. = rValue;
	//int(10) = 5; -> 임시 객체. 줄이 끝나면 사라진다.

	//Player()._hp = 10; //Player() : 이름이 없는 객체.

	//Player&&(); // 우측값 참조

	Player* p = new Player();
	Player* p2 = new Player(*p);

	Player* p3 = new Player(std::move(*p2));

	//단 하나만 존재해야 하는 ptr
	//unique_ptr<Player> unique_p = make_unique<Player>(1);
	//unique_ptr<Player> unique_p2 = std::move(unique_p);

	FuncRefRef(Player()); //임시 객체를 우측값 참조로 넘긴다. 임시객체는 사용 후 바로 버린다.
	Func(std::move(*p)); //*p를 우측값 참조로 넘긴다. => *p는 이 후 껍데기만 남는다.
	
	//Func(std)



	delete p;
	delete p2;
	delete p3;

	Func(*new Player());


	cout << "-------------------------------" << endl;

	vector<Player> players;
	Player p4;

	players.push_back(Player()); //이동생성자 호출
	players.push_back(p4); //복사생성자 호출.
	players.push_back();
	players.emplace_back(Player());

	return 0 ;
}