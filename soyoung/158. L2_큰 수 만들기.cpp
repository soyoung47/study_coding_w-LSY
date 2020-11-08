//https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    string str = number;
    char max;
    int ind;
    while (1)
    {
        if (k == 0)  return answer + str;
        else if (k == str.size())    return answer;

        max = *max_element(str.begin(), str.begin() + k + 1);
        ind = str.find_first_of(max);
        k -= ind;

        answer += max;
        str = str.substr(ind + 1);
    }
}