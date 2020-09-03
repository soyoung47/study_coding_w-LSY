//[programmers.co.kr] - 코딩테스트 연습 - 2020 KAKAO BLIND RECRUITMENT - 자물쇠와 
//https://programmers.co.kr/learn/courses/30/lessons/60059

#include <string>
#include <vector>
using namespace std;

vector<vector<int>> rotation(vector<vector<int>> key)
{
    vector<vector<int>> tmpKey;
    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            tmpKey[j][key.size()-i-1] = key[i][j];
        }
    }
    return tmpKey;
}

bool chkPos(int ii, int jj, vector<vector<int>> lock, vector<vector<int>> key, int n, int M, int N)
{
    vector<vector<int>> newMat ( n, vector<int>(n,0));
    //fill lock in newMat
    for (int i = M - 1; i <= M + N - 2; i++)
    {
        for (int j = M - 1; j <= M + N - 2; j++)
        {
            newMat[i][j] = lock[i + 1 - M][j + 1 - M];
        }
    }
    //add key in newMat
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            newMat[i + ii][j + jj] = newMat[i + ii][j + jj] + key[i][j];
        }
    }
    //check elements
    for (int i = M - 1; i < M + N - 2; i++)
    {
        for (int j = M - 1; j < M + N - 2; j++)
        {
            if (newMat[i][j] != 1) return 0;
        }
    }
    return 1;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int N = lock.size(), M = key.size();
    const int n = 2*M + (N-2);

    for (int r = 0; r < 4; r++) //90, 180, 270, 360
    {
        for (int ii = 0; ii <= M+N-2; ii++) //maximum expansion x 
        {
            for (int jj = 0; jj <= M+N-2; jj++) //maximum expansion y 
            {
                bool chkP = chkPos(ii, jj, lock, key, n, M, N);
                if (chkP == 1) return 1;
            }
        }
        key = rotation(key);
    }
    return 0;
}
