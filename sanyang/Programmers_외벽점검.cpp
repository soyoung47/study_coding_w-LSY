//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 외벽 점검
//https://programmers.co.kr/learn/courses/30/lessons/60062

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Worked[15];
int Covered[15];
int ans = 9;

int DFS(int frd, vector<int>& weak, vector<int>& dist)
{
    bool ifEnd = 1;

    for (int i = 0; i < weak.size(); i++)
    {
        //all cover X
        if (Covered[i] == 0) ifEnd = 0;
    }

    if (ifEnd && frd > 0) return ans = min(ans, frd);
    //cover X + no friends
    else if (!ifEnd && frd > 8) return -1;

    for (int i = 0; i < dist.size(); i++)
    {
        if (Worked[i] == 0)
        {
            for (int j = 0; j < weak.size(); j++)
            {
                if (Covered[j] == 0)
                {
                    int t = 0;
                    while (j + t < weak.size() && weak[j] + dist[i] >= weak[j + t])
                    {
                        Covered[j + t] = 1;
                        t++;
                    }
                    break;
                }
            }

            Worked[i] = 1;
            DFS(frd + 1, weak, dist);
            Worked[i] = 0;
            for (int i = 0; i < 15; i++) Covered[i] = 0;
        }
    }
    return ans;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.rbegin(), dist.rend());
    for (int i = 0; i < 15; i++)
    {
        Worked[i] = 0;
        Covered[i] = 0;
    }

    for (int i = 0; i < weak.size(); i++)
    {
        DFS(0, weak, dist);
        int start = weak[0] + n;
        for (int p = 1; p < weak.size(); p++)
            weak[p - 1] = weak[p];
        weak[weak.size() - 1] = start;
    }

    if (ans> 8) ans = -1;
    return ans;
}

//ref: https://keykat7.blogspot.com/2019/10/2020.html
