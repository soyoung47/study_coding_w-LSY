//https://programmers.co.kr/learn/courses/30/lessons/42577

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

    for (int i = 0; i < size-1; i++)
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