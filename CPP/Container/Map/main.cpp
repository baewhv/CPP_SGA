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

	//userid�� 555�� �ָ� ã�� ��... vector - �ִ� n
	for (int i = 0; i < userInfoDatas.size(); i++)
	{
		if (userInfoDatas[i].userId == 555)
		{
			cout << "find" << endl;
			break;
		}
	}

	//�ؽ� ���̺� unordered map
	unordered_map<int, User*> myUm;
	//Ű���� �ؽ� ����� ������ �ڷ������� ����.

	//�ؽ� ���̺� ������ �Է� ��� 1. 
	myUm[0] = &users[0];

	//�ؽ� ���̺� ������ �Է� ��� 2. pair�� ����� insert�� ���� �ִ´�.
	pair<int, User*> p = { 2, &users[2] };
	myUm.insert(p);

	//�ߺ�ó���� ���� ������ ���� ���� ���������.
	if (myUm.count(0) == 0)
		myUm[0] = &users[1];

	//�ߺ�üũ�� ��ȯ�ϴ� pair
	pair<unordered_map<int, User*>::iterator, bool> insertPair = myUm.insert(p);

	for (int i = 0; i < users.size(); i++)
	{
		myUm[i] = &users[i];
	}

	//Ű ���� �Է��Ͽ� �ؽ� ����� �����Ͽ� ���� index�� ���� ���� ��ȯ.
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
		//map iterator�� key value�� ���Ե� pair�� ��ȯ�Ѵ�.
		cout << (*myMIter).second->userId << endl;
		cout << (*myMIter).second->userData << endl;
	}

	return 0;
}