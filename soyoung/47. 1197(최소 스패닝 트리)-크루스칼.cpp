#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, ans;
vector < pair<int, pair<int, int>>> cost;
int parent[10001];

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
bool sameparent(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y)
		return false;
	else
		return true;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y)
		parent[y] = x;
}
void MST_k()
{
	sort(cost.begin(), cost.end());

	//크루스칼 알고리즘
	for (int k = 0; k < cost.size(); k++)
	{
		pair<int, int> p = cost[k].second;

		if (!sameparent(p.first, p.second))
		{
			Union(p.first, p.second);
			ans += cost[k].first;
		}
	}
}
int main()
{
	cost.clear();
	ans = 0;

	cin >> V >> E;

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		cost.push_back(make_pair(c, make_pair(a, b)));
	}

	for (int j = 1; j <= V; j++)
		parent[j] = j;

	MST_k();

	cout << ans;
}
