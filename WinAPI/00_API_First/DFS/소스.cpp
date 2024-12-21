#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<bool>> adj2;
vector<bool> visited;

//인접 행렬
void CreateGraph_Matrix()
{ 
	adj2.resize(7, vector<bool>(7, false));
	visited = vector<bool>(7, false);
	//7x7 초기화법.

	adj2[0][0] = true;
	//adj2[0][1] = true;
	adj2[0][2] = true;

	//adj2[1][0] = true;
	adj2[1][1] = true;
	adj2[1][4] = true;
	adj2[1][5] = true;

	adj2[2][0] = true;
	adj2[2][2] = true;
	adj2[2][3] = true;

	adj2[3][3] = true;
	adj2[3][2] = true;

	adj2[4][4] = true;
	adj2[4][1] = true;
	adj2[4][6] = true;

	adj2[5][1] = true;
	adj2[5][5] = true;

	adj2[6][4] = true;
	adj2[6][6] = true;

}

void DFS(int here)
{
	visited[here] = true;
	cout << here << "방문" << endl;

	for (int there = 0; there < adj2.size(); there++)
	{
		if (adj2[here][there] == false) //인접 체크.
			continue;
		if (visited[there] == true)
			continue;
		DFS(there);
	}
	return;
}

void DFS_ALL() //끊겨있는 노드 탐색하여 몇개의 그래프가 나오는지
{
	int count = 0;
	for (int i = 0; i < adj2.size(); i++)
	{
		if (visited[i] == false)
		{
			count++;
			DFS(i);
		}
	}
}

int main()
{
	CreateGraph_Matrix();
	DFS_ALL();

	return 0;
}