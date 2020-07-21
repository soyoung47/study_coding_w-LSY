//Codility_L7-3_StacksandQueues_Nesting[Painless]
//https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/

#include <string>
#include <stack>

int solution(string &S)
{
    stack<char> s;
    int cnt = 0;
    int lenS = int(S.size());
    if (lenS == 0) return 1;
    else if (lenS%2 == 1) return 0;
    else
    {
        for (int i=0; i<lenS; i++)
        {
            if (S[i] == '(')
            {
                s.push(S[i]);
                cnt++;
            }
            if (S[i] == ')')
            {
                s.pop();
                cnt--;
                if (cnt < 0) return 0;
            }
        }
        if (s.empty()) return 1;
        else return 0;
    }
}

//result O(N), 100%: https://app.codility.com/demo/results/training85JJ8F-NDX/
