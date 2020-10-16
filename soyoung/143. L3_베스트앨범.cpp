//https://programmers.co.kr/learn/courses/30/lessons/42579

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp1(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool comp2(pair<int,int> a, pair<int,int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    unordered_map<string, int> m, ind_genres;

    //�帣�� �� ��� Ƚ�� ����
    for (int i = 0; i < size; i++)
        m[genres[i]] += plays[i];

    //�� ��� Ƚ���� ���� ������� �帣 index �ο�
    vector<pair<string, int>> tmp(m.begin(), m.end());
    sort(tmp.begin(), tmp.end(), comp1);

    int n = m.size();   //�帣 ����    
    for (int i = 0; i < n; i++)
        ind_genres[tmp[i].first] = i;

    //�帣�� {�뷡 ��� Ƚ��, ������ȣ    
    vector<vector<pair<int, int>>> v(n);    
    for (int i = 0; i < size; i++)
        v[ind_genres[genres[i]]].push_back({ plays[i], i });

    //��� Ƚ�� �� ������ȣ�� �������� ����
    for (int i = 0; i < n; i++)
        sort(v[i].begin(), v[i].end(), comp2);

    //����Ʈ �ٹ� ���ϰ� ����
    for (int i = 0; i < n; i++)
    {
        answer.push_back(v[i][0].second);

        if(v[i].size() > 1)
            answer.push_back(v[i][1].second);
    }

    return answer;
}