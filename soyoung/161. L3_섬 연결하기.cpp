//https://programmers.co.kr/learn/courses/30/lessons/42861

#include <vector>
#include <queue>
using namespace std;

void prim(vector<vector<pair<int, int>>> v, vector<bool>& visit, int& answer)
{
	//cost 오름차순
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	//1번부터 시작
	visit[0] = true;

	for (int i = 0; i < v[0].size(); i++)
	{
		int next = v[0][i].first;
		int next_cost = v[0][i].second;

		pq.push({ next_cost, next });
	}

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_cost = pq.top().first;
		pq.pop();

		if (visit[cur])	continue;

		visit[cur] = true;
		answer += cur_cost;

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int next_cost = v[cur][i].second;

			pq.push({ next_cost, next });
		}
	}
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

	vector<vector<pair<int,int>>> v(n);
	vector<bool> visit(n, false);

    for (int i = 0; i < costs.size(); i++)
    {
        int from = costs[i][0], to = costs[i][1], cost = costs[i][2];
        v[from].push_back({ to, cost });
        v[to].push_back({ from, cost });
    }

    prim(v, visit, answer);

    return answer;
}