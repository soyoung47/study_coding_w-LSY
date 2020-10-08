//https://programmers.co.kr/learn/courses/30/lessons/68645

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> vv(num, 0);
        v.push_back(vv);
        num++;
    }

    int value = 1, inner = n;
    int i = 0, j = 0;
    int a = -1, b, x, y;
    while(inner > 0)
    {
        //down
        for (j = 0; j < inner; j++)
        {
            x = a + 1 + j;
            v[x][i] = value++;
        }
        //side
        inner--;
        for (j = 0; j < inner; j++)
        {
            y = j + i + 1;
            v[x][y] = value++;
        }
        //up
        inner--;
        for (j = 0; j < inner; j++)
        {
            a = x - j - 1;
            b = y - j - 1;
            v[a][b] = value++;
        }
        inner--;
        i++;
    }

    //print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            answer.push_back(v[i][j]);
        }
    }

    return answer;
}