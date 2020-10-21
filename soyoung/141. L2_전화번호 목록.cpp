//https://programmers.co.kr/learn/courses/30/lessons/42577

/***Solution 2: 해시***/

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    unordered_map<string, int> m;
    map<int, int> len_m;

    for (string phone : phone_book) m[phone] = 1;

    for (auto iter : m)
    {
        int len = iter.first.size();

        for (string phone : phone_book)
        {
            if (len > phone.size())  continue;
            if (iter.first == phone) continue;
            if (m[phone.substr(0, len)] == 1) return false;
        }
    }

    return answer;
}


/***Solution 1: 정렬***/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    int size = phone_book.size();
    sort(phone_book.begin(), phone_book.end(), comp);

    for (int i = 0; i < size - 1; i++)
    {
        int len = phone_book[i].size();

        for (int j = i + 1; j < size; j++)
        {
            if (phone_book[i] == phone_book[j].substr(0, len))
                return false;
        }
    }

    return answer;
}