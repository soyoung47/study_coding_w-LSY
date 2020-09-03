//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 기둥과 보 설치
//https://programmers.co.kr/learn/courses/30/lessons/60061

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool row[101][101], col[101][101];

bool buildRow(int x, int y)
{
    return col[x][y-1] || col[x+1][y-1] || (row[x-1][y] && row[x+1][y]);
}

bool buildCol(int x, int y)
{
    return y==1 || col[x][y-1] || row[x-1][y] || row[x][y];
}

bool remove(int n)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (row[i][j] && !buildRow(i, j)) return 0;
            if (col[i][j] && !buildCol(i, j)) return 0;
        }
    }
    return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for (int i=1; i<= 101; i++)
    {
        for (int j=1; j<=101; j++) row[i][j] = col[i][j] = 0;
    }
    for (int i=0; i<build_frame.size(); i++)
    {
        int x = build_frame[i][0], y = build_frame[i][1], a = build_frame[i][2], b = build_frame[i][3];
        x++; y++;
        if (b == 0) //remove
        {
            if (a == 0) //vertical
            {
                col[x][y] = 0;
                if (remove(n+1)) continue;
                col[x][y] = 1;
            }
            else if (a == 1) //horizontal
            {
                row[x][y] = 0;
                if (remove(n+1)) continue;
                row[x][y] = 1;
            }
        }
        else if (b == 1) //build
        {
            if (a == 0) // vertical
            {
                if (buildCol(x,y)) col[x][y] = 1;
            }
            else if (a == 1)
            {
                if (buildRow(x,y)) row[x][y] = 1;
            }
        }
    }
    
    vector<vector<int>> ans;
    for (int i=1; i<=n+1; i++)
    {
        for (int j=1; j<=n+1; j++)
        {
            if (row[i][j] == 1) ans.push_back({i-1,j-1,1});
            if (col[i][j] == 1) ans.push_back({i-1,j-1,0});
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
