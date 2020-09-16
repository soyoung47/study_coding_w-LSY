//https://programmers.co.kr/learn/courses/30/lessons/17678

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int size = timetable.size();
    
    vector<int> crew;
    for (int i = 0; i < size;i++)
    {
        int hh = stoi(timetable[i].substr(0, 2));
        int mm = stoi(timetable[i].substr(3, 2));
        crew.push_back(hh * 60 + mm);
    }
    sort(crew.begin(), crew.end());

    vector<vector<int>> shuttle(n);
    int time = 9 * 60 - t, j = 0;
    for (int i = 0; i < n; i++)
    {
        time += t;
        while (shuttle[i].size() < m && j < size)
        {
            if (crew[j] > time) break;
            shuttle[i].push_back(crew[j]);
            j++;
        }        
    }

    int ans = 0;
    int lastBUS = shuttle[n - 1].size();
    if (lastBUS < m) ans = time;
    else ans = shuttle[n - 1][lastBUS - 1] - 1;

    string sh = to_string(ans / 60);
    string sm = to_string(ans % 60);

    if (sh.size() == 1)  sh = "0" + sh;
    if (sm.size() == 1)    sm = "0" + sm;
    
    answer = sh + ":" + sm;

    return answer;
}