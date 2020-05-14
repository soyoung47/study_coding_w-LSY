//#1197. Minimum Spanning Tree (Kruskal algorithm)
//https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>
#include <utility> //pair
#include <algorithm> //sort,pair
#define MAX 100000
#define endl '\n'
using namespace std;
vector<pair<int, pair<int, int>>> edge;
int Parent[MAX];
int numPC, numLine, minCost;

int Find_Parent(int x)
{
	if (Parent[x] == x) return x;
	else return Parent[x] = Find_Parent(Parent[x]);
}

bool SameParent(int x, int y)
{
	x = Find_Parent(x);
	y = Find_Parent(y);
	if (x == y) return true;
	else return false;
}

void Union(int x, int y)
{
	x = Find_Parent(x);
	y = Find_Parent(y);
	if (x != y)
	{
		Parent[y] = x;
	}
}

void Solve()
{
	sort(edge.begin(), edge.end());
	for (int i = 1; i <= numPC; i++) Parent[i] = i;
	for (int i = 0; i < numLine; i++)
	{
		if (SameParent(edge[i].second.first, edge[i].second.second) == false)
		{
			Union(edge[i].second.first, edge[i].second.second); //from, to
			minCost += edge[i].first; //cost
		}
	}
	cout << minCost << endl;
}

int main(int argc, char** argv)
{
	cin >> numPC >> numLine;
	for (int i = 0; i < numLine; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back(make_pair(cost, make_pair(from, to)));
	}

	Solve();

	return 0;
}
