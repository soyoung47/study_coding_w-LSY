//https://programmers.co.kr/learn/courses/30/lessons/64065

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> v;
    unordered_map<int, int> m;

    //Ʃ�� ���Ϳ� ����
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '{' && isdigit(s[i + 1]))
        {
            i++;
            vector<int> tmp;
            string str = "";
            while (s[i] != '}')
            {
                if (isdigit(s[i]))   str += s[i];
                if (s[i + 1] == ',' || s[i + 1] == '}')
                {
                    tmp.push_back(stoi(str));
                    str = "";
                }
                i++;
            }
            v.push_back(tmp);
        }        
    }
    
    //Ʃ�� ���� ������ �������� �������� ����
    sort(v.begin(), v.end(), comp);

    //s�� ǥ���ϴ� Ʃ�� �迭 ã��
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (m.count(v[i][j]) > 0)    continue;
            answer.push_back(v[i][j]);
            m[v[i][j]] = 1;
        }
    }

    return answer;
}