//https://programmers.co.kr/learn/courses/30/lessons/42628

/***Solution 2***/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {

    vector<int> v;

    for (string op : operations)
    {
        if (op[0] == 'I')    v.push_back(stoi(op.substr(2)));
        else
        {
            if (v.empty())   continue;

            if (op == "D 1")    sort(v.begin(), v.end());
            else    sort(v.begin(), v.end(), greater<int>());

            v.pop_back();
        }
    }

    //최대값, 최소값 반환
    if (v.empty())  return { 0,0 };
    else
    {
        sort(v.begin(), v.end());
        return { v[v.size() - 1], v[0] };
    }
}

/***Solution 1***/
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    unordered_map<int, int> m;  //숫자, 개수
    priority_queue<int, vector<int>, less<int>> pq_max; //내림차순
    priority_queue<int, vector<int>, greater<int>> pq_min;  //오름차순

    for (string op : operations)
    {
        if (op == "D 1")
        {
            while (1)
            {
                if (pq_max.empty())  break;
                int n = pq_max.top();
                pq_max.pop();
                if (m[n] != 0)
                {
                    m[n]--;
                    break;
                }
            }
        }
        else if (op == "D -1")
        {
            while (1)
            {
                if (pq_min.empty())  break;
                int n = pq_min.top();
                pq_min.pop();
                if (m[n] != 0)
                {
                    m[n]--;
                    break;
                }
            }
        }
        else
        {
            int num = stoi(op.substr(2));
            pq_max.push(num);
            pq_min.push(num);
            m[num]++;
        }
    }

    //각 큐에서 이미 pop된 숫자 pop하기
    while (!pq_max.empty() && m[pq_max.top()] == 0) pq_max.pop();
    while (!pq_min.empty() && m[pq_min.top()] == 0) pq_min.pop();

    //최대값, 최소값 반환
    if (pq_max.empty())  return { 0,0 };
    else    return { pq_max.top(), pq_min.top() };

}