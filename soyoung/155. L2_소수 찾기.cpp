//https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <unordered_set>
using namespace std;

void dfs(int cnt, int n, string numbers, string& select, unordered_set<int>& s, vector<bool>& visit)
{
    if (cnt == n)
    {
        s.insert(stoi(select));
        return;
    }

    for (int i = 0; i < visit.size(); i++)
    {
        if (visit[i])    continue;
        visit[i] = true;
        select.push_back(numbers[i]);
        dfs(cnt + 1, n, numbers, select, s, visit);
        select.pop_back();
        visit[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<char>());

    int max_num = stoi(numbers);

    //�����佺�׳׽��� ü
    vector<bool> check(max_num + 1, true);
    check[0] = check[1] = false;

    for (int i = 2; i <= sqrt(max_num); i++)    //i: ������ ��
    {
        if (!check[i])  continue;
        for (int j = i * 2; j <= max_num; j += i)    //i �����ϰ� i��� ����
            check[j] = false;
    }

    //������ ����
    unordered_set<int> s;
    for (int i = 1; i <= numbers.size(); i++)
    {
        vector<bool> visit(numbers.size(), false);
        string select = "";
        dfs(0, i, numbers, select, s, visit);
    }

    //������ ������ �Ҽ����� üũ
    for (auto iter = s.begin(); iter != s.end(); iter++)
        if (check[*iter]) answer++;
    
    return answer;
}