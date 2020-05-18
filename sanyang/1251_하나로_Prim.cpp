//#1251. SW문제해결응용 4일차 - 하나로 (Prim algorithm)
#include <iostream>
#include <vector>
#include <cstring> //memset
#include <queue> //priority_queue
#define endl '\n'
#define MAX 1001
typedef long long ll;
typedef struct
{
	ll x;
	ll y;
}Pos;
using namespace std;
Pos P[MAX];
bool Visit[MAX];
vector <pair<int, ll>> Cost[MAX]; //int, ll
double E;
ll totalD;
int ni;
ll minC;

void Initialize()
{
	memset(Visit, 0, sizeof(Visit));
	E = 0.0;
	totalD = 0;
	minC = 0;
	ni = 0;
	//Cost->clear();
	for (int i = 0; i < MAX; i++) Cost[i].clear();
	for (int i = 0; i < MAX; i++)
	{
		P[i].x = -1;
		P[i].y = -1;
	}
}

void Prim(int start)
{
	priority_queue<pair<ll, int>> PQ; //ll, int

	for (int i = 0; i < Cost[start].size(); i++)
	{
		int Next = Cost[start][i].first; //int
		ll Distance = Cost[start][i].second;
		PQ.push(make_pair(-Distance, Next));
	}
	Visit[start] = true;

	while (PQ.empty() == 0)
	{
		ll Distance = -PQ.top().first;
		int Cur = PQ.top().second; //int
		PQ.pop();

		if (Visit[Cur] == false)
		{
			Visit[Cur] = true;
			totalD += Distance;

			for (int i = 0; i < Cost[Cur].size(); i++)
			{
				ll nDistance = Cost[Cur][i].second;
				int Next = Cost[Cur][i].first; //int
				if (Visit[Next] == false)	PQ.push(make_pair(-nDistance, Next));
			}
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc = 0;
	cin >> tc;

	for (int test = 0; test < tc; test++)
	{
		Initialize();
		cin >> ni;

		for (int i = 0; i < ni; i++)	cin >> P[i].x;

		for (int i = 0; i < ni; i++)	cin >> P[i].y;

		cin >> E;

		for (int i = 0; i < ni; i++)
		{
			for (int j = 0; j < ni; j++)
			{
				ll Dist = ((P[i].x - P[j].x) * (P[i].x - P[j].x)) + ((P[i].y - P[j].y) * (P[i].y - P[j].y));
				Cost[i].push_back(make_pair(j, Dist));
				Cost[j].push_back(make_pair(i, Dist));
			}
		}

		//Solution
		Prim(1);

		ll minC = totalD * E + 0.5;
		cout << "#" << test + 1 << " " << minC << endl;
	}

	return 0;
}

