#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool h[102][102];   //기둥 설치여부
bool w[102][102];   //보 설치여부
int N;

//기둥, 보 설치
bool install(int x, int y, int a)
{
    //기둥 설치
    if (a == 0)
    {
        //바닥 위
        if (y == 0)    return true;
        
        //다른 기둥 위 
        if (h[x][y - 1]) return true;

        //보의 왼쪽 끝 위
        if (x > 0 && w[x - 1][y])  return true;

        //보의 오른쪽 끝 위
        if (w[x][y])  return true;
    }
    //보 설치
    else
    {  
        //바닥이 아님 && 한쪽 끝 부분이 기둥 위
        if (y > 0 && h[x][y - 1])  return true;
        if (y > 0 && x < N && h[x + 1][y - 1])   return true;
        
        //양쪽 끝 부분이 다른 보와 동시 연결
        if (x > 0 && x < N && w[x - 1][y] && w[x + 1][y])
            return true;
    }

    return false;
}

//기둥, 보 철거
bool demolish(int x, int y, int a)
{
    //기둥 철거
    if (a == 0)     //0<= x <= N, 0<= y <= N-1
    {
        h[x][y] = false;

        //위에 기둥이 있는 경우 철거 불가
        if (h[x][y + 1])
        {
            if (!install(x, y + 1, 0))  return false;
        }            

        /*위에 보가 있는 경우, 그 보가 설치 불가능하면 철거 불가*/
        //오른쪽에 보가 있다면, (x,y+1) ~ (x+1, y+1)
        if (w[x][y + 1])
        {
            if (!install(x, y + 1, 1))   return false;
        }

        //왼쪽에 보가 있다면, (x-1,y+1) ~ (x, y+1)
        if (x > 0 && w[x - 1][y + 1])
        {
            if (!install(x-1, y + 1, 1))   return false;
        }

        return true;
    }
    //보 철거
    else     //0<= x <= N-1, 1<= y <= N
    {
        w[x][y] = false;

        //왼쪽 끝 위 기둥이 설치 불가능하면 철거 불가
        if (h[x][y])
        {
            if (!install(x, y, 0))  return false;
        }

        //오른쪽 끝 위 기둥이 설치 불가능하면 철거 불가
        if (h[x + 1][y])
        {
            if (!install(x + 1, y, 0))  return false;
        }

        //오른쪽 보가 설치 불가능하면 철거 불가
        if (w[x + 1][y])
        {
            if (!install(x + 1, y, 1))   return false;
        }
        //왼쪽 보와 연결되어 있다면,
        if (x > 0 && w[x - 1][y])
        {
            if (!install(x - 1, y, 1))   return false;
        }

        return true;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    N = n;
    
    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];

        //설치
        if (build_frame[i][3] == 1)
        {            
            if (install(x, y, build_frame[i][2]))
            {
                if (build_frame[i][2] == 0)
                    h[x][y] = true;
                else
                    w[x][y] = true;
            }                
        }
        //철거
        else
        {
            if (!demolish(x, y, build_frame[i][2]))
            {
                if (build_frame[i][2] == 0)
                    h[x][y] = true;
                else
                    w[x][y] = true;
            }
        }            
    }

    //최종 구조물 상태 저장
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (h[i][j])    answer.push_back({ i,j,0 });
            if (w[i][j])    answer.push_back({ i,j,1 });
        }
    }

    return answer;
}

//Ref:::https://blog.naver.com/iambigman97/221906235063