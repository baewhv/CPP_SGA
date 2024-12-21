//#include <queue>
//#include <list>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
////Graph
////���Ϸ��� ����.
////���ø��� �ٸ��� �����ϴ� ������ �ذ��ϱ� ���� ���ܳ� ����.
//
////���� ����Ʈ
//// -> ����Ʈ�� ����� ���� �������� �ð��� �����ɸ���. �ʿ��� ��ŭ�� ������ �Ҵ��Ѵ�.
////���� ���
//// -> Ž�� �ӵ��� ��������� ������ ������ ���� �Ҵ��ؾ��Ѵ�.
//
//
//
//vector<vector<int>> adjList;
//vector<vector<bool>> adj2;
//
////���� ���
//void CreateGraph_Matrix()
//{
//	adj2.resize(7, vector<bool>(7, false));
//	//7x7 �ʱ�ȭ��.
//
//	adj2[0][0] = true;
//	adj2[0][1] = true;
//	adj2[0][2] = true;
//
//	adj2[1][0] = true;
//	adj2[1][1] = true;
//	adj2[1][4] = true;
//	adj2[1][5] = true;
//
//	adj2[2][0] = true;
//	adj2[2][2] = true;
//	adj2[2][3] = true;
//
//	adj2[3][3] = true;
//	adj2[3][2] = true;
//
//	adj2[4][4] = true;
//	adj2[4][1] = true;
//	adj2[4][6] = true;
//
//	adj2[5][1] = true;
//	adj2[5][5] = true;
//
//	adj2[6][4] = true;
//	adj2[6][6] = true;
//
//}
//
////���� ����Ʈ
//void CreateGraph_List()
//{
//	adjList.resize(7);
//	adjList[0].push_back(0);
//	adjList[0].push_back(1);
//	adjList[0].push_back(2);
//
//	adjList[1].push_back(0);
//	adjList[1].push_back(1);
//	adjList[1].push_back(4);
//	adjList[1].push_back(5);
//
//	adjList[2].push_back(0);
//	adjList[2].push_back(2);
//	adjList[2].push_back(3);
//
//	adjList[3].push_back(3);
//	adjList[3].push_back(2);
//
//	adjList[4].push_back(4);
//	adjList[4].push_back(1);
//	adjList[4].push_back(6);
//
//	adjList[5].push_back(1);
//	adjList[5].push_back(5);
//
//	adjList[6].push_back(4);
//	adjList[6].push_back(6);
//}
//
//
//int main()
//{
//	CreateGraph_List();
//
//	auto it = find(adjList[3].begin(), adjList[3].end(), 6);
//	if (it != adjList[3].end())
//		cout << "�ֽ��ϴ�" << endl;
//	else
//		cout << "���� �ȵ�" << endl;
//	CreateGraph_Matrix();
//	if (adj2[4][1])
//		cout << "����" << endl;
//	else
//		cout << "�����ȵ�" << endl;
//
//	return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string message;
    getline(cin, message);

    string toByte = "";
    for (auto m : message)
    {
        string temp = "";
        int itoC = static_cast<int>(m);
        while (itoC != 0)
        {
            temp += to_string(itoC % 2);
            itoC /= 2;
        }
        reverse(temp.begin(), temp.end());
        toByte += temp;
    }
    int combo = 0;
    int before = -1;
    string temp = "";
    for (int t = 0; t < toByte.length() + 1; t++)
    {
        int i = -1;
        if (t != toByte.length())
            i = toByte[t] == '0' ? 0 : 1;

        if (before == -1)
        {
            before = i;
            combo++;
        }
        else if (i == before)
        {
            combo++;
        }
        else if (i != before || t == toByte.length())
        {
            if (before == 0)
            {
                temp += "00 " + string(combo, '0');
                before = 1;
            }
            else if (before == 1)
            {
                temp += "0 " + string(combo, '0');
                before = 0;
            }
            combo = 1;
            if (t != toByte.length())
                temp += " ";
        }

    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << temp << endl;
}