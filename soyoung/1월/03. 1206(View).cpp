#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int width = 0;
        cin >> width;
        //���� ����
        int floor[width];
        for (int n = 0; n < width; n++)
            cin >> floor[n];
        //������ Ȯ�� ���� ����
        int prospect = 0;

        for (int i = 2; i < width - 2; i++)
        {
            int min = 300;
            if (floor[i] > floor[i - 2] && floor[i] > floor[i - 1] && floor[i] > floor[i + 1] && floor[i] > floor[i + 2])
            {
                if (floor[i] - floor[i - 2] < min)
                    min = floor[i] - floor[i - 2];
                if (floor[i] - floor[i - 1] < min)
                    min = floor[i] - floor[i - 1];
                if (floor[i] - floor[i + 1] < min)
                    min = floor[i] - floor[i + 1];
                if (floor[i] - floor[i + 2] < min)
                    min = floor[i] - floor[i + 2];

                prospect += min;
            }
        }

        //����� ���
        cout << "#" << test_case << " " << prospect << "\n";

    }
    return 0;
}