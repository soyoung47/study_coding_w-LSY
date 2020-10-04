//https://programmers.co.kr/learn/courses/30/lessons/67259

#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };    //하, 좌, 상, 우
int dy[4] = { 0, -1, 0, 1 };

struct car {
    int x, y, dir;
};

int solution(vector<vector<int>> board) {
    
    int N = board.size();
    int answer = N*N*600;

    int visit[26][26][4] = { false };
    int dist[26][26][4] = { 0 };   //건설 비용
    queue<car> q;

    visit[0][0][0] = visit[0][0][3] = true;
    q.push({ 0, 0, 0 });
    q.push({ 0, 0, 3 });

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int cost = dist[x][y][dir];
        q.pop();

        if (x == N - 1 && y == N - 1)
        {
            answer = answer < cost ? answer : cost;
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncost = cost;

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)   continue;
            if (board[nx][ny] == 1)  continue;

            if (dir == i)  //직선 도로
                ncost += 100;
            else  //코너
                ncost += 600;

            if (!visit[nx][ny][i] || ncost < dist[nx][ny][i])
            {
                visit[nx][ny][i] = true;
                q.push({ nx, ny, i});
                dist[nx][ny][i] = ncost;
            }
        }        
    }

    return answer;
}