#include<iostream>

using namespace std;

int N, limit, max_score, sum_kcal;
int score[20];
int kcal[20];

void find_max_score(int index, int sum, int max)
{
    if (sum > limit) return;
    if (index == N)
    {
        if (max > max_score)
            max_score = max;
        return;
    }

    find_max_score(index + 1, sum + kcal[index], max + score[index]);
    find_max_score(index + 1, sum, max);
}

int main()
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        //����� ��, ���� Į�θ�
        cin >> N >> limit;

        //��Ằ �� ����, Į�θ�
        for (int i = 0; i < N; i++)
        {
            cin >> score[i] >> kcal[i];
        }

        //�ְ����� ã��
        max_score = -1;
        sum_kcal = 0;

        find_max_score(0, 0, 0);

        //����� ���
        cout << "#" << test_case << " " << max_score << "\n";
    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}