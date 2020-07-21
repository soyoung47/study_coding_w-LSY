//Codility_L7-4_StacksandQueues_StoneWall[Painless]
//https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/

#include <stack>

int solution(vector<int> &H)
{
    int cnt = 0;
    stack<int> s;

    for (int i=0; i<int(H.size()); i++)
    {
        if (s.empty() || H[i] > s.top())
        {
            s.push(H[i]);
        }
        else if (H[i] < s.top())
        {
            while(H[i] < s.top())
            {
                s.pop();
                cnt++;
                if (s.empty()) break;
            }
            if (s.empty()) s.push(H[i]);
            else if (H[i] != s.top()) s.push(H[i]);
        }
    }
    cnt += int(s.size());
    return cnt;
}

//result O(N), 100%: https://app.codility.com/demo/results/training4AG9YG-B2U/
