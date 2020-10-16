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

    //장르별 총 재생 횟수 저장
    for (int i = 0; i < size; i++)
        m[genres[i]] += plays[i];

    //총 재생 횟수가 많은 순서대로 장르 index 부여
    vector<pair<string, int>> tmp(m.begin(), m.end());
    sort(tmp.begin(), tmp.end(), comp1);

    int n = m.size();   //장르 개수    
    for (int i = 0; i < n; i++)
        ind_genres[tmp[i].first] = i;

    //장르별 {노래 재생 횟수, 고유번호    
    vector<vector<pair<int, int>>> v(n);    
    for (int i = 0; i < size; i++)
        v[ind_genres[genres[i]]].push_back({ plays[i], i });

    //재생 횟수 및 고유번호를 기준으로 정렬
    for (int i = 0; i < n; i++)
        sort(v[i].begin(), v[i].end(), comp2);

    //베스트 앨범 수록곡 선정
    for (int i = 0; i < n; i++)
    {
        answer.push_back(v[i][0].second);

        if(v[i].size() > 1)
            answer.push_back(v[i][1].second);
    }

    return answer;
}