#include<iostream>

using namespace std;
int N, M;
int go(int k)
{
    int a = k * N;
    M--;
    if (M == 0)    return a;
    else go(a);
}
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> test_case;
        cin >> N >> M;
        int ans = go(1);
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}