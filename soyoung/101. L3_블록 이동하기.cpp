#include <string>
#include <vector>
#include <queue>
using namespace std;

struct robot
{
    int x, y, d, t;
};

bool visit[101][101][4];

//우(0), 하(1), 좌(2), 상(3): 시계방향 (x-행, y-열)
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> board) {

    int N = board[0].size();

    //로봇의 시작점 (0,0)-우
    queue<robot> q;
    robot start = { 0, 0, 0, 0 };
    q.push(start);

    //BFS
    while (!q.empty())
    {
        robot rb = q.front();
        q.pop();
        if (visit[rb.x][rb.y][rb.d]) continue;
        visit[rb.x][rb.y][rb.d] = true;

        //로봇이 목적지에 도착했으면, return 소요시간
        if ((rb.x == N - 1 && rb.y == N - 1) || (rb.x + dx[rb.d] == N - 1 && rb.y + dy[rb.d] == N - 1))
            return rb.t;

        //상하좌우 이동
        for (int i = 0; i < 4; i++)
        {
            int x = rb.x + dx[i];
            int y = rb.y + dy[i];
            int d = rb.d;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (x < 0 || x >= N || y < 0 || y >= N || nx < 0 || nx >= N || ny < 0 || ny >= N)   continue;
            if (board[x][y] == 0 && board[nx][ny] == 0 && !visit[x][y][d])
                q.push({ x, y, d, rb.t + 1 });
        }

        //회전
        for (int i = 0; i < 2; i++) //축
        {
            //기준점이 축이면
            int x = rb.x;
            int y = rb.y;
            int d = rb.d;

            if (i == 1) //다른점이 축이면
            {
                x = x + dx[d];
                y = y + dy[d];
                d = (d + 2) % 4;
            }

            for (int j = 0; j < 2; j++)//회전방향
            {
                int nd = (d + 1) % 4; //시계방향
                if (j == 1)//반시계방향
                    nd = (d + 3) % 4;

                //회전 후 로봇이 위치하는 좌표
                int nx = x + dx[nd];
                int ny = y + dy[nd];

                //회전할 때 지나는 대각선 좌표
                int rx = nx + dx[d];
                int ry = ny + dy[d];

                if (rx < 0 || rx >= N || ry < 0 || ry >= N || nx < 0 || nx >= N || ny < 0 || ny >= N)   continue;
                if (board[rx][ry] == 0 && board[nx][ny] == 0 && !visit[x][y][nd])
                {
                    if (i == 0)    q.push({ x, y, nd, rb.t + 1 });
                    else    q.push({ nx, ny, (nd + 2) % 4, rb.t + 1 });
                }
            }
        }
    }
    return 0;
}

//Ref:::https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/, https://blog.naver.com/oyh951416/222063379802
