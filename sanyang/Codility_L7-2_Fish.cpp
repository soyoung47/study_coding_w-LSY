//Codility_L7-2_StacksandQueues_Fish[Painless]
//https://app.codility.com/programmers/lessons/7-stacks_and_queues/fish/

#include <stack>

int solution(vector<int> &A, vector<int> &B)
{
    stack<int> s;
    s.push(0);
    for (int i=1; i<int(A.size()); i++)
    {
        if (B[s.top()] <= B[i]) s.push(i);
        else
        {
            while (B[s.top()] != B[i])
            {
                if (A[i] > A[s.top()])
                {
                    s.pop();
                    if (s.empty()) s.push(i);
                    else if (B[s.top()] == B[i]) s.push(i);
                }
                else break;
            }
        }
    }
    return int(s.size());
}

//result O(N), 100%: https://app.codility.com/demo/results/trainingGRT5B3-BMB/ 
