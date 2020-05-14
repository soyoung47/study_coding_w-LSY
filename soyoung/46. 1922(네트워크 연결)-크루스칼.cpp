#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int N, M, ans;
vector<pair<int, pair<int, int>>> cost;
int parent[1001];

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
	//����ġ ���� ������ ū �������� ����
	sort(cost.begin(), cost.end());

	//ũ�罺Į �˰���
	for (int k = 0; k < cost.size(); k++)
	{
		pair<int, int> p = cost[k].second;

		if (!sameparent(p.first, p.second))
		{
			Union(p.first, p.second);	//����
			ans += cost[k].first;	//��� ���ϱ�
		}
	}
}
int main()
{
	cost.clear();
	ans = 0;

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cost.push_back(make_pair(c, make_pair(a,b)));
	}

	for (int j = 1; j <= N; j++)
		parent[j] = j;
	
	MST_k();

	cout << ans;

	return 0;
}