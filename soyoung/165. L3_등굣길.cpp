//https://programmers.co.kr/learn/courses/30/lessons/42898

#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

    vector<vector<int>> map(n + 1, vector<int>(m + 1, 0));

    //�������� üũ
    for (int i = 0; i < puddles.size(); i++)
        map[puddles[i][1]][puddles[i][0]] = -1;

    //�� ��ǥ������ �ִ� �Ÿ� ���ϱ�
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)   //�����
            {
                map[i][j] = 1;
                continue;
            }

            //��������
            if (map[i][j] == -1)    map[i][j] = 0;
            else    map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
        }
    }

    return map[n][m];
}

//n,m �� �����ϱ�!!!