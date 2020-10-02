https://programmers.co.kr/learn/courses/30/lessons/60060

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

//트라이 구조
struct Trie
{
    bool finish;
    int count;
    Trie* node[26];

    Trie()
    {
        finish = false;
        count = 0;
        memset(node, NULL, sizeof(node));
    }

    //문자열 삽입
    void insert(const char* str)
    {
        //문자열이 끝나는 지점인 경우
        if (*str == NULL)   
        {
            finish = true;
            return;
        }

        int cur = *str - 'a';
        if (node[cur] == NULL)   node[cur] = new Trie(); //탐색이 처음인 경우
        count++;
        node[cur]->insert(str + 1); //다음 문자
    }

    //문자열 찾기
    int find(const char* str)
    {
        int cur = *str - 'a';
        if (*str == '?')    return count;
        if (node[cur] == NULL)   return 0;
        return node[cur]->find(str + 1);
    }
};

Trie* dict[100001];
Trie* rdict[100001];

vector<int> solution(vector<string> words, vector<string> queries) {

    vector<int> answer;


    //가사 뒤집어서 저장
    vector<string> rwords = words;
    for (int i = 0; i < rwords.size(); i++)
        reverse(rwords[i].begin(), rwords[i].end());

    //가사 등록(삽입)    
    for (int i = 0; i < words.size(); i++)
    {
        int size = words[i].size();
        if (dict[size] == NULL)
        {
            dict[size] = new Trie();
            rdict[size] = new Trie();
        }
        dict[size]->insert(words[i].c_str());
        rdict[size]->insert(rwords[i].c_str());
    }

    //가사 검색
    for (int i = 0; i < queries.size(); i++)
    {
        int size = queries[i].size();
        string s = queries[i];
        
        if (s[0] != '?')
        {
            if (dict[size] == NULL) answer.push_back(0);
            else answer.push_back(dict[size]->find(s.c_str()));            
        }
        else
        {
            reverse(s.begin(), s.end());

            if (rdict[size] == NULL) answer.push_back(0);
            else answer.push_back(rdict[size]->find(s.c_str()));
        }
    }

    return answer;
}
