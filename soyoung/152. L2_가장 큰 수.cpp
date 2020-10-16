//https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    int size = numbers.size();

    //���� string���� ��ȯ
    vector<string> num;
    for (int i = 0; i < size; i++)
        num.push_back(to_string(numbers[i]));

    //����
    sort(num.begin(), num.end(), comp);

    if (num[0] == "0") return "0";

    for (string str : num)
        answer += str;

    return answer;
}