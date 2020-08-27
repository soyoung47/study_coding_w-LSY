#include <string>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int>> rotation90(vector<pair<int, int>> arr, int M)
{    
    for (int i = 0; i < arr.size(); i++)
    {
        pair<int, int> p = arr[i];
        arr[i] = make_pair(p.second, M - 1 - p.first);
    }
    return arr;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    int N = lock.size();
    int M = key.size();

    //�ڹ��� Ȩ�� ���� ���� ��ǥ ����
    //vector<pair<int, int>> lock_groove; //�ڹ��� Ȩ(0)
    map<pair<int, int>, int> lock_groove;
    vector<pair<int, int>>   key_bump;  //���� ����(1)

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (lock[i][j] == 0)
                lock_groove[make_pair(i, j)] = 1;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (key[i][j] == 1)
                key_bump.push_back(make_pair(i, j));
        }
    }

    if (lock_groove.size() > key_bump.size())    return false;

    //ȸ�� 3��(90,180,270)
    for (int r = 0; r < 4;r++)
    {
        //���������� �̵�(0 ~ N-1)
        for (int i = -M +1; i < N + M; i++)
        {
            //�Ʒ��� �̵�
            for (int j = -M + 1; j < N + M; j++)
            {
                //����, �ڹ��� Ȯ��
                int cnt = 0;
                for (int k = 0; k < key_bump.size(); k++)
                {
                    int x = key_bump[k].first + i;
                    int y = key_bump[k].second + j;

                    if (x < 0 || y < 0 || x >= N || y >= N)    continue;
                                       
                    if (lock[x][y] == 1)    cnt = 0;     //������ ����� �ڹ����� ����� ������ �ȵ�.
                    if (lock_groove.count(make_pair(x, y)) > 0)   cnt++;
                }
                if (cnt == lock_groove.size())  return true;
            }
        }

        //ȸ��
        key_bump = rotation90(key_bump, M);
    }

    return false;
}