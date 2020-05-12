#include<iostream>
#include<memory.h>
using namespace std;

int R, C, ans;
char map[21][21];
bool visit[21][21];
bool check[30]; //¾ËÆÄºª Ã¼Å©
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void suzy(int x, int y, int cnt)
{
    if (ans < cnt)
        ans = cnt;

    if (ans == 'Z' - 'A' + 1)
        return;

    check[map[x][y] - 'A'] = true;
    visit[x][y] = true;

    for (int k = 0; k < 4; k++)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];

        if (xx < 0 || xx >= R || yy < 0 || yy >= C)
            continue;

        if (!visit[xx][yy] && !check[map[xx][yy] - 'A'])
            suzy(xx, yy, cnt + 1);
    }

    check[map[x][y] - 'A'] = false;
    visit[x][y] = false;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> R >> C;

        ans = 0;
        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        memset(check, false, sizeof(check));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
                cin >> map[i][j];
        }

        suzy(0, 0, 1);

        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}