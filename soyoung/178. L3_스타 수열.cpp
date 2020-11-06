//https://programmers.co.kr/learn/courses/30/lessons/70130

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    if (n < 2)    return 0;

    unordered_map<int, int> m;
    for (int num : a)   m[num]++;

    vector<pair<int, int>> pq;  //개수, 숫자
    for (auto tmp : m)  pq.emplace_back(tmp.second, tmp.first);

    sort(pq.begin(), pq.end());

    while (!pq.empty())
    {
        int max = pq.back().second;
        if (answer / 2 > pq.back().first) break;
        pq.pop_back();

        vector<int> v;
        bool include = false;

        for (int i = 0; i < n; i++)
        {
            if (v.size() % 2 == 0)
            {
                if (i == n - 1)    break;
                v.emplace_back(a[i]);
                if (a[i] == max) include = true;
            }
            else
            {
                if (v.back() == a[i])    continue;
                if (include)
                {
                    v.emplace_back(a[i]);
                    include = false;
                }
                else
                {
                    if (a[i] == max)
                        v.emplace_back(a[i]);
                }
            }
        }
        if (v.size() % 2 != 0)   v.pop_back();
        answer = answer > v.size() ? answer : v.size();
    }

    return answer;
}