#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//mordern C++ = c++11 ���� �߰��� ��.
//6. using
//  typedef�� ��ɻ����δ� ����.
//  typedef�� ���ø��� ȣȯ���� �ʴ´�.
typedef unsigned int UINT;
using UINT2 = unsigned int;


//typedef�� ������
template<typename T>
using MyV = std::vector<T>;

//template<typename T>
//typedef std::vector<T> MyVv;

//7. enum class
// �������� �̸��� ��ĥ �� ���.
enum PlayerType
{
	NONE,
	KNIGHT,
	MAGE,
	ARCHER

};

enum class ItemType
{
	NONE,
	POTION,
	ARMOR,
	WEAPON
};

//8. lamda
//9. shift ����(�̵�������, std::move)
//10. ����Ʈ������






int main()
{
	PlayerType type = PlayerType::NONE;
	PlayerType type2 = static_cast<PlayerType>(1); //���ڸ� �־� enum�� Ÿ���� ������ �� �ִ�.
	int type3 = static_cast<PlayerType>(2); //���ڷ� ������ �� �� �ִ�.
	int type3 = NONE; //���ڷ� ������ �� �� �ִ�.

	NONE;

}