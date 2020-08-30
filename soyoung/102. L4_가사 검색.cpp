#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    if (a.size() == b.size())   return a < b;
    else   return a.size() < b.size();
}

vector<int> solution(vector<string> words, vector<string> queries) {
    
    vector<int> answer;

    //단어 뒤집어서 저장
    vector<string> rwords = words;
    for (int i = 0; i < rwords.size(); i++)
    {
        reverse(rwords[i].begin(), rwords[i].end());
    }

    //길이, 사전순 기준으로 정렬
    sort(words.begin(), words.end(), comp);
    sort(rwords.begin(), rwords.end(), comp);

    //검색 키워드에 해당하는 가사 단어 개수 찾기
    for (int i = 0; i < queries.size(); i++)
    {
        string str = queries[i];
        int size = str.size();

        int lower, upper, ind, len;

        //?가 접두사에 있으면,
        if (str[0] == '?')
        {           
            reverse(str.begin(), str.end());//키워드 뒤집기
            ind = str.find_first_of('?');   //?가 나오는 index
            len = size - ind;

            str.replace(ind, len, len, 'a');   //?를 'a'로 치환
            lower = lower_bound(rwords.begin(), rwords.end(), str, comp) - rwords.begin();

            str.replace(ind, len, len, 'z');   //?를 'z'로 치환
            upper = upper_bound(rwords.begin(), rwords.end(), str, comp) - rwords.begin();
        }
        //?가 접미사에 있으면,
        else
        {
            ind = str.find_first_of('?');   //?가 나오는 index
            len = size - ind;

            str.replace(ind, len, len, 'a');   //?를 'a'로 치환
            lower = lower_bound(words.begin(), words.end(), str, comp) - words.begin();

            str.replace(ind, len, len, 'z');   //?를 'z'로 치환
            upper = upper_bound(words.begin(), words.end(), str, comp) - words.begin();
        }

        answer.push_back(upper - lower);
    }

    return answer;
}

//Ref:::https://regularmember.tistory.com/201 (이분탐색)