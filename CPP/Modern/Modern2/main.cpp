#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//mordern C++ = c++11 이후 추가된 것.
//6. using
//  typedef와 기능상으로는 동일.
//  typedef는 템플릿과 호환되지 않는다.
typedef unsigned int UINT;
using UINT2 = unsigned int;


//typedef와 차이점
template<typename T>
using MyV = std::vector<T>;

//template<typename T>
//typedef std::vector<T> MyVv;

//7. enum class
// 열거형의 이름이 겹칠 때 사용.
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
//9. shift 개념(이동생성자, std::move)
//10. 스마트포인터






int main()
{
	PlayerType type = PlayerType::NONE;
	PlayerType type2 = static_cast<PlayerType>(1); //숫자를 넣어 enum의 타입을 정의할 수 있다.
	int type3 = static_cast<PlayerType>(2); //숫자로 저장해 둘 수 있다.
	int type3 = NONE; //숫자로 저장해 둘 수 있다.

	NONE;

}