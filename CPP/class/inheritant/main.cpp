#include <iostream>

using namespace std;

//���
//is - a ����
//Animal, Cat
//Cat is a Animal = (O)
//Animal is a Cat = (X) // ������ �ٸ�.

//1. �θ��� public, protected �Ӽ��� ����� ��� �����޴´�.
// => �ڵ��� ���뼺

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