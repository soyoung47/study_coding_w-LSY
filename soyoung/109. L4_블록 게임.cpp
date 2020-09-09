#include <vector>
using namespace std;

int N;
vector<vector<int>> b;

bool isEmpty(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        if (b[i][y] != 0)
            return false;
    }
    return true;
}

bool isRemove(int x, int y, int w, int h)
{
    int value = -1;
    int blank = 0;

    for (int i = x; i < x + h; i++)
    {
        for (int j = y; j < y + w; j++)
        {
            if (b[i][j] == 0)
            {
                blank++;
                if (blank > 2)   return false;
                if (!isEmpty(i, j))   return false;
            }
            else
            {
                if (value != -1 && b[i][j] != value)    return false;
                value = b[i][j];
            }
        }
    }

    for (int i = x; i < x + h; i++)
    {
        for (int j = y; j < y + w; j++)
        {
            b[i][j] = 0;
        }
    }

    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    b = board;
    N = board.size();
    int cnt;

    do {
         cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i <= N - 2 && j <= N - 3 && isRemove(i, j, 3, 2))
                    cnt++;
                else if (i <= N - 3 && j <= N - 2 && isRemove(i, j, 2, 3))
                    cnt++;
            }
        }
        answer += cnt;
    } while (cnt);
    
    return answer;
}

//Ref:::https://blog.naver.com/csezsw/221552568049