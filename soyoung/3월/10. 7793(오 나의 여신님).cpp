#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int N, M, gx, gy;
char map[51][51];
bool s_visit[51][51], d_visit[51][51];
int dist[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> sq, dq;


void devil()
{
    int dq_size = dq.size();

    for (int a = 0; a < dq_size; a++)
    {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop();

        for (int b = 0; b < 4; b++)
        {
            int new_x = x + dx[b];
            int new_y = y + dy[b];

            if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
                continue;

            if (!d_visit[new_x][new_y] && (map[new_x][new_y] == 'S' || map[new_x][new_y] == '.'))
            {
                d_visit[new_x][new_y] = true;
                map[new_x][new_y] = '*';
                dq.push(make_pair(new_x, new_y));
            }
        }
    }

    return;
}
void suyeon()
{
    while (!sq.empty())
    {
        devil();    //¾Ç¸¶ÀÇ ¼Õ¾Æ±Í

        int sq_size = sq.size();

        for (int a = 0; a < sq_size; a++)
        {
            int x = sq.front().first;
            int y = sq.front().second;
            sq.pop();

            for (int b = 0; b < 4; b++)
            {
                int xx = x + dx[b];
                int yy = y + dy[b];

                if (xx < 0 || xx >= N || yy < 0 || yy >= M)
                    continue;

                if (!s_visit[xx][yy] && (map[xx][yy] == '.' || map[xx][yy] == 'D'))
                {
                    s_visit[xx][yy] = true;
                    sq.push(make_pair(xx, yy));
                    dist[xx][yy] = dist[x][y] + 1;
                }
            }
        }
    }

    return;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        N = 0, M = 0;
        cin >> N >> M;

        memset(map, 0, sizeof(map));
        memset(s_visit, false, sizeof(s_visit));
        memset(d_visit, false, sizeof(d_visit));
        memset(dist, 0, sizeof(dist));

        while (!sq.empty())
            sq.pop();
        while (!dq.empty())
            dq.pop();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'S')
                {
                    s_visit[i][j] = true;
                    sq.push(make_pair(i, j));
                }
                else if (map[i][j] == '*')
                {
                    d_visit[i][j] = true;
                    dq.push(make_pair(i, j));
                }
                else if (map[i][j] == 'D')
                {
                    gx = i;
                    gy = j;
                }
            }
        }

        suyeon();

        if (dist[gx][gy] == 0)
            cout << "#" << test_case << " GAME OVER\n";
        else
            cout << "#" << test_case << " " << dist[gx][gy] << "\n";
    }
    return 0;
}