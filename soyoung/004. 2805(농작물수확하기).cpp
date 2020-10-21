#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    int N, sum;
    int** farm;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;

        farm = new int* [N];
        for (int i = 0; i < N; i++)
        {
            farm[i] = new int[N];
        }

        sum = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%1d", &farm[i][j]);
                sum += farm[i][j];
            }
        }

        int mid = N / 2;
        for (int k = 0; k < mid; k++)
        {
            for (int l = 0; l < mid; l++)
            {
                if ((k + l) < mid)
                {
                    sum -= farm[k][l];
                    sum -= farm[N - k - 1][N - l - 1];
                    sum -= farm[N - k - 1][l];
                    sum -= farm[k][N - l - 1];
                }
            }
        }

        cout << "#" << test_case << " " << sum << "\n";

    }
    return 0;
}