//https://programmers.co.kr/learn/courses/30/lessons/68936

#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = { 0,0 };

    int N = arr.size();
    vector< vector<int >> zero(N, vector<int>(N + 1));
    vector< vector<int >> one(N, vector<int>(N + 1));

    //0,1 sum of count 저장
    for (int i = 0; i < N; i++)
    {
        int zero_sum = 0, one_sum = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 0) zero_sum++;
            else    one_sum++;

            zero[i][j + 1] = zero_sum;
            one[i][j + 1] = one_sum;
        }

        answer = { answer[0] + zero_sum, answer[1] + one_sum };
    }

    int k = 2;
    vector<vector<int>> ans;
    while (k <= N)
    {
        //2개 행의 0,1 개수 합
        vector<vector<int>> new_zero, new_one;
        for (int i = 0; i < zero.size(); i += 2)
        {
            vector<int> tmp0(N + 1, 0), tmp1(N + 1, 0);
            for (int j = 1; j <= N; j++)
            {
                tmp0[j] += zero[i][j] + zero[i + 1][j];
                tmp1[j] += one[i][j] + one[i + 1][j];
            }

            new_zero.push_back(tmp0);
            new_one.push_back(tmp1);
        }

        zero = new_zero, one = new_one;

        //압축 가능한지 확인
        int square = k * k;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < zero.size(); i++)
        {
            for (int j = k; j <= N; j += k)
            {
                if (zero[i][j] - zero[i][j - k] == square)   cnt0++;
                if (one[i][j] - one[i][j - k] == square)   cnt1++;
            }
        }

        if (cnt0 == 0 && cnt1 == 0)  break;

        ans.push_back({ cnt0, cnt1, square });
        k *= 2;
    }

    //겹치는 부분 제거
    for (int i = 0; i < ans.size() - 1; i++)
    {
        ans[i][0] -= ans[i + 1][0] * 4;
        ans[i][1] -= ans[i + 1][1] * 4;
    }

    //answer 구하기
    for (int i = 0; i < ans.size(); i++)
        answer = { answer[0] - (ans[i][2] - 1) * ans[i][0], answer[1] - (ans[i][2] - 1) * ans[i][1] };

    return answer;
}
