//https://programmers.co.kr/learn/courses/30/lessons/42895

#include <vector>
#include <unordered_set>
using namespace std;

int solution(int n, int number) {
    int answer = -1;
    
    if (n == number)   return 1;

    unordered_set<int> s[9];
    s[0].insert(n);

    for (int i = 2; i < 9; i++)
    {
        //숫자 붙이기
        int tmp = 0;
        for (int j = 0; j < i; j++)
            tmp = tmp * 10 + n;

        s[i - 1].insert(tmp);
    }
    
    for (int i = 1; i < 9; i++)
    {   
        for (int j = 0; j < i; j++)
        {
            for (auto& x : s[j])
            {
                for (auto& y : s[i-j-1])
                {
                    s[i].insert(x + y);
                    s[i].insert(x - y);
                    s[i].insert(x * y);
                    if(y != 0)
                        s[i].insert(x / y);
                }
            }
        }
        if (s[i].find(number) != s[i].end())
            return i + 1;
    }

    return answer;
}

//ref::: https://gurumee92.tistory.com/164
