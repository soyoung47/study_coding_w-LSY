//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 블록 이동하기
//https://programmers.co.kr/learn/courses/30/lessons/60063

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos{
    int y[2], x[2];
    int dir[2];
};

int n;
bool chk[101][101][4];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

bool range(int y1, int x1, int y2, int x2, int dir1, int dir2, vector<vector<int>> &mp)
{
    return !(y1<0 || y1>=n || x1<0 || x1>=n || y2<0 || y2>=n || x2<0 || x2>=n || mp[y1][x1] || mp[y2][x2]);
}

int solution(vector<vector<int>> mp) {
    n = mp.size();
    queue<pos> q;
    
    chk[0][0][0] = chk[0][1][2] = 1;
    q.push({0,0,0,1,0,2});
    int timer = 0;
    while(!q.empty())
    {
        int len = q.size();
        while(len--)
        {
            pos front = q.front();
            q.pop();
            
            if ((front.y[0] == n-1 && front.x[0] == n-1) || (front.y[1] == n-1 && front.x[1] == n-1))
                return timer;
            
            for (int dir=0; dir<4; dir++)
            {
                int ny1 = front.y[0] + dy[dir], nx1 = front.x[0] + dx[dir];
                int ny2 = front.y[1] + dy[dir], nx2 = front.x[1] + dx[dir];
                int dir1 = front.dir[0], dir2 = front.dir[1];
                
                if(!range(ny1, nx1, ny2, nx2, dir1, dir2, mp) || chk[ny1][nx1][dir1] ||
                   chk[ny2][nx2][dir2]) continue;
                chk[ny1][nx1][dir1] = chk[ny2][nx2][dir2] = 1;
                q.push({ny1, ny2, nx1, nx2, dir1, dir2});
            }
            
            for (int i=-1; i<=1; i++)
            {
                if (i==0) continue;
                for (int j=0; j<2; j++)
                {
                    int y = front.y[j], x = front.x[j];
                    int dir = (front.dir[j] + i + 4)%4;
                    int prev_dir = (dir - i + 4)%4;
                    int oppo_dir = (dir + 2)%4;
                    
                    int ny2 = y+dy[dir], nx2 = x+dx[dir];
                    int ny3 = y+dy[dir]+dy[prev_dir], nx3 = x+dx[dir]+dx[prev_dir];
                    
                    if (!range(ny2,nx2,ny3,nx3,dir,oppo_dir, mp) || chk[y][x][dir] || chk[ny2][nx2][oppo_dir])
                        continue;
                    chk[y][x][dir] = chk[ny2][nx2][oppo_dir] = 1;
                    q.push({y, ny2, x, nx2, dir, oppo_dir});
                }
            }
        }
        timer += 1;
    }
}
