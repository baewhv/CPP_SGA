#include <iostream>

using namespace std;

//상속
//is - a 관계
//Animal, Cat
//Cat is a Animal = (O)
//Animal is a Cat = (X) // 범위가 다름.

//1. 부모의 public, protected 속성과 기능을 모두 물려받는다.
// => 코드의 재사용성

class Animal
{
public:
	void Eat()
	{
		cout << "yam" << endl;
	}
	int mouth;
protected:
	
};



class Cat : public Animal
{
public:
	int legs;

private:
};


int main()
{
	Cat cat;
	cat.Eat();

	cat.mouth = 1;
	cat.legs = 2;


	cout << sizeof(Animal) << endl;
	cout << sizeof(Cat) << endl;
	cout << sizeof(cat) << endl;

	return 0;
}