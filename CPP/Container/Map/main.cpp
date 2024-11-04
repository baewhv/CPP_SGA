#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

struct User
{
	int userId;
	int userData;
};

struct UserInfo
{
	int userId;
	User* user;
};

int main()
{
	vector<User> users;
	users.reserve(1000);
	for (int i = 0; i < 1000; i++)
	{
		users.push_back({ i,i % 100 });
	}

	vector<UserInfo> userInfoDatas;
	userInfoDatas.reserve(1000);

	for (int i = 0; i < users.size(); i++)
	{
		User user = users[i];
		userInfoDatas.push_back({ user.userId, &users[i] });
	}

	//userid가 555인 애를 찾을 때... vector - 최대 n
	for (int i = 0; i < userInfoDatas.size(); i++)
	{
		if (userInfoDatas[i].userId == 555)
		{
			cout << "find" << endl;
			break;
		}
	}

	//해쉬 테이블 unordered map
	unordered_map<int, User*> myUm;
	//키값은 해쉬 계산이 가능한 자료형으로 설정.

	//해쉬 테이블 데이터 입력 방법 1. 
	myUm[0] = &users[0];

	//해쉬 테이블 데이터 입력 방법 2. pair를 만들어 insert를 통해 넣는다.
	pair<int, User*> p = { 2, &users[2] };
	myUm.insert(p);

	//중복처리를 하지 않으면 기존 값이 덮어씌워진다.
	if (myUm.count(0) == 0)
		myUm[0] = &users[1];

	//중복체크를 반환하는 pair
	pair<unordered_map<int, User*>::iterator, bool> insertPair = myUm.insert(p);

	for (int i = 0; i < users.size(); i++)
	{
		myUm[i] = &users[i];
	}

	//키 값을 입력하여 해쉬 계산을 적용하여 나온 index를 통해 값을 반환.
	myUm[555];

	map<int, User*> myM;

	for (int i = 0; i < users.size(); i++)
	{
		myM[i] = &users[i];
	}

	for (int i = 0; i < myM.size(); i++)
	{
		cout << myM[i]->userId << endl;
		cout << myM[i]->userData << endl;
	}

	const map<int, User*>::const_iterator myMIter = myM.begin();

	for (myMIter; myMIter != myM.end(); myMIter)
	{
		//map iterator는 key value가 포함된 pair를 반환한다.
		cout << (*myMIter).second->userId << endl;
		cout << (*myMIter).second->userData << endl;
	}

	return 0;
}