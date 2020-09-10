#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    unordered_map<string, int> ma;
    unordered_map<string, int> mb;
    unordered_map<string, int> m;

    //다중집합 만들기(str1)
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    for (int i = 0; i < str1.size() - 1; i++)
    {
        string str = str1.substr(i, 2);
        if (isalpha(str[0]) && isalpha(str[1]))
            ma[str] += 1;
    }

    //다중집합 만들기(str2)
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    for (int i = 0; i < str2.size() - 1; i++)
    {
        string str = str2.substr(i, 2);
        if (isalpha(str[0]) && isalpha(str[1]))
            mb[str] += 1;
    }

    if (ma.size() == 0 && mb.size() == 0)    return 65536;

    //자카드 유사도 구하기
    for (auto it = ma.begin(); it != ma.end(); it++)
        m[it->first] += it->second;
    for (auto it = mb.begin(); it != mb.end(); it++)
        m[it->first] += it->second;

    double n_intersaction = 0, n_union = 0, j = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second > 1)
        {
            n_intersaction += min(ma[it->first], mb[it->first]);
            n_union += max(ma[it->first], mb[it->first]);
        }
        else
            n_union += 1;
    }

    j = n_intersaction / n_union;
    answer = j * 65536;

    return answer;
}