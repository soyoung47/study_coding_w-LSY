//https://programmers.co.kr/learn/courses/30/lessons/17676

#include <string>
#include <vector>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    int size = lines.size();
    vector<int> t_start, t_end;

    for (int i = 0; i < size; i++)
    {
        lines[i].pop_back();
        int h = stoi(lines[i].substr(11, 2)) * 60 * 60 * 1000;
        int m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
        int s = stoi(lines[i].substr(17, 2)) * 1000;
        int ms = stoi(lines[i].substr(20, 3));
        int t_process = stof(lines[i].substr(24)) * 1000;

        t_start.push_back(h + m + s + ms - t_process + 1);
        t_end.push_back(h + m + s + ms);
    }

    for (int i = 0; i < size; i++)
    {
        int cnt = 0;
        for (int j = i; j < size; j++)
        {
            if (t_start[j] < t_end[i] + 1000)  cnt++;
        }

        answer = answer > cnt ? answer : cnt;
    }

    return answer;
}