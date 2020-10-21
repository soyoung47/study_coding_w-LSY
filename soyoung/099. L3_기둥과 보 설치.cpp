#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool h[102][102];   //��� ��ġ����
bool w[102][102];   //�� ��ġ����
int N;

//���, �� ��ġ
bool install(int x, int y, int a)
{
    //��� ��ġ
    if (a == 0)
    {
        //�ٴ� ��
        if (y == 0)    return true;
        
        //�ٸ� ��� �� 
        if (h[x][y - 1]) return true;

        //���� ���� �� ��
        if (x > 0 && w[x - 1][y])  return true;

        //���� ������ �� ��
        if (w[x][y])  return true;
    }
    //�� ��ġ
    else
    {  
        //�ٴ��� �ƴ� && ���� �� �κ��� ��� ��
        if (y > 0 && h[x][y - 1])  return true;
        if (y > 0 && x < N && h[x + 1][y - 1])   return true;
        
        //���� �� �κ��� �ٸ� ���� ���� ����
        if (x > 0 && x < N && w[x - 1][y] && w[x + 1][y])
            return true;
    }

    return false;
}

//���, �� ö��
bool demolish(int x, int y, int a)
{
    //��� ö��
    if (a == 0)     //0<= x <= N, 0<= y <= N-1
    {
        h[x][y] = false;

        //���� ����� �ִ� ��� ö�� �Ұ�
        if (h[x][y + 1])
        {
            if (!install(x, y + 1, 0))  return false;
        }            

        /*���� ���� �ִ� ���, �� ���� ��ġ �Ұ����ϸ� ö�� �Ұ�*/
        //�����ʿ� ���� �ִٸ�, (x,y+1) ~ (x+1, y+1)
        if (w[x][y + 1])
        {
            if (!install(x, y + 1, 1))   return false;
        }

        //���ʿ� ���� �ִٸ�, (x-1,y+1) ~ (x, y+1)
        if (x > 0 && w[x - 1][y + 1])
        {
            if (!install(x-1, y + 1, 1))   return false;
        }

        return true;
    }
    //�� ö��
    else     //0<= x <= N-1, 1<= y <= N
    {
        w[x][y] = false;

        //���� �� �� ����� ��ġ �Ұ����ϸ� ö�� �Ұ�
        if (h[x][y])
        {
            if (!install(x, y, 0))  return false;
        }

        //������ �� �� ����� ��ġ �Ұ����ϸ� ö�� �Ұ�
        if (h[x + 1][y])
        {
            if (!install(x + 1, y, 0))  return false;
        }

        //������ ���� ��ġ �Ұ����ϸ� ö�� �Ұ�
        if (w[x + 1][y])
        {
            if (!install(x + 1, y, 1))   return false;
        }
        //���� ���� ����Ǿ� �ִٸ�,
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

        //��ġ
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
        //ö��
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

    //���� ������ ���� ����
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