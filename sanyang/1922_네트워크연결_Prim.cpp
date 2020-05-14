//#1922. Connect Network (Prim algorithm)
//https://www.acmicpc.net/problem/1922
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1002
#define endl '\n'
using namespace std;
typedef pair<int, int> pii;
bool Visit[MAX];
vector<pair<int, int>> Cost[MAX];
int minCost;

void Prim(int start)
{
	priority_queue<pair<int, int>> PQ;
	//priority_queue<pair<int, int>, vector<pair<int, int>>> PQ;
	//priority_queue<pii, vector<pii>, greater<pii>> PQ;
	for (int i = 0; i < Cost[start].size(); i++) //size(): # of elements
	{
		int Next = Cost[start][i].first; 
		int Distance = Cost[start][i].second;
		PQ.push(make_pair(-Distance, Next)); //push: insert(=push_back)
	}
	Visit[start] = true;

	while (PQ.empty() == 0)
	{
		int Distance = -PQ.top().first; //top(): return the top ele
		int Cur = PQ.top().second; //Current
		PQ.pop();

		if (Visit[Cur] == false)
		{
			Visit[Cur] = true;
			minCost += Distance;
			for (int i = 0; i < Cost[Cur].size(); i++)
			{
				int nDistance = Cost[Cur][i].second;
				int Next = Cost[Cur][i].first;
				if (Visit[Next] == false) PQ.push(make_pair(-nDistance, Next));
			}
		}
	}
	cout << minCost << endl;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int numPC, numLine;
	cin >> numPC >> numLine;
	for (int i = 0; i < numLine; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		Cost[from].push_back(make_pair(to, cost));
		Cost[to].push_back(make_pair(from, cost));
		//edge.push_back(make_pair(cost, make_pair(from, to)));
	}

	Prim(1);

	return 0;
}
