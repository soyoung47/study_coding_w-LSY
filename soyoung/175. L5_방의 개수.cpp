//https://programmers.co.kr/learn/courses/30/lessons/49190

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    int size = arrows.size();

    //�� 3�� �̻� = ��
    if (size < 3)    return answer;

    //�̵� ����
    int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    //�̵� �� ���� ���� �ľ�
    map<pair<int, int>, int> point; //����� ��ǥ(int,int), �� ��ǥ�� ��� Ƚ��
    map<pair<pair<int, int>, pair<int, int>>, int> line; //����(��ǥ1, ��ǥ2), ������ ����
    pair<int, int> p = { 0,0 }; //ù ������ ��ǥ
    point[p] = 1;

    for (int move : arrows)
    {   
        //                          * - * - *
        //  * - *                     �� ��
        //    X      �� ���� ���   *   *   *    �� �����Ͽ� �߰� �������� ��ǥ�� üũ�� �� �ֵ��� 2���� ����
        //  * - *                     ��  ��
        //                          * - * - *
        for (int i = 0; i < 2; i++)
        {
            //�̵�
            pair<int, int> np = { p.first + dx[move],  p.second + dy[move] };

            //�̹� ����� �����̶�� pass
            if (line.count({ p, np }) > 0)
            {
                p = np;
                continue;
            }

            //�̹� ����� ������ �ƴ϶��,

            //1. ��� ��ǥ ���� + Ƚ�� �߰�, ���� ����
            point[np]++;
            line[{ p, np }]++;
            line[{ np, p }]++;

            //2. ��� Ƚ�� == 2 : �� 1��, Ƚ�� �ʱ�ȭ
            if (point[np] == 2)
            {
                answer++;
                point[np] = 1;
            }

            p = np;
        }        
    }

    return answer;
}