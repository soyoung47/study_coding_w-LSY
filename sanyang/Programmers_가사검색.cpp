//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 
//https://programmers.co.kr/learn/courses/30/lessons/60060

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//binary search

bool comp(string a, string b)
{
    if (a.size() < b.size()) return 1;
    else if (a.size() == b.size())
    {
        if (a < b) return 1;
    }
    return 0;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> ans;
    
    vector<string> rwords = words; //reverse words
    int size = rwords.size();
    for (int i=0; i<size; i++) reverse(rwords[i].begin(), rwords[i].end());
    
    //sort by comp
    sort(words.begin(), words.end(), comp);
    sort(rwords.begin(), rwords.end(), comp);
    
    int len, low, high, idx;
    
    for (auto query: queries)
    {
        len = query.size();
        
        if (query[0] == '?') //start with ?
        {
            reverse(query.begin(), query.end());
            idx = query.find_first_of('?');
            
            for (int i=idx; i<len; i++)
                query[i] = 'a';
            low = lower_bound(rwords.begin(), rwords.end(), query, comp) - rwords.begin();
            
            for (int i=idx; i<len; i++)
                query[i] = 'z';
            high = upper_bound(rwords.begin(), rwords.end(), query, comp) - rwords.begin();
        }
        
        else // end with ?
        {
            idx = query.find_first_of('?');
            
            for (int i=idx; i<len; i++)
                query[i] = 'a';
            low = lower_bound(words.begin(), words.end(), query, comp) - words.begin();
            
            for (int i=idx; i<len; i++)
                query[i] = 'z';
            high = upper_bound(words.begin(), words.end(), query, comp) - words.begin();
        }
        ans.push_back(high-low);
    }
    return ans;
}
