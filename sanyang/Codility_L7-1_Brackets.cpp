//Codility_L7-1_StacksandQueues_Brackets[Painless]
//https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/

#include <string>
#include <stack>

int solution(string &S)
{
    stack<char> s;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int lenS = int(S.size());
    if (lenS == 0) return 1;
    else if (lenS%2 == 1) return 0;
    else
    {
        for (int i=0; i<lenS; i++)
        {
            if (S[i] == '{' || S[i] == '[' || S[i] == '(')
            {
                s.push(S[i]);
                if (S[i] == '{') cnt1++;
                if (S[i] == '[') cnt2++;
                if (S[i] == '(') cnt3++;
            }
            else
            {
                if (S[i] == ')')
                {
                    if (s.top() == '(')
                    {
                        cnt3--;
                        if (cnt3 < 0) return 0;
                        s.pop();
                    }
                    else return 0;
                }
                if (S[i] == ']')
                {
                    if (s.top() == '[' || s.top() == ')')
                    {
                        cnt2--;
                        if (cnt2 < 0) return 0;
                        s.pop();
                    }
                    else return 0;
                }
                if (S[i] == '}')
                {
                    if (s.top() == '{' || s.top() == ']' || s.top() == ']')
                    {
                        cnt1--;
                        if (cnt1 < 0) return 0;
                        s.pop();
                    }
                    else return 0;
                }
            }
        }
        if (s.empty()) return 1;
        else return 0;
    }
}

//result O(N), 100%: https://app.codility.com/demo/results/trainingABYZTP-9MM/
