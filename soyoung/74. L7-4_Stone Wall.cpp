/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/training75UX3E-TG6/
    Reference:::https://ergate.tistory.com/entry/Codility-StoneWall
*/
#include <stack>

int solution(vector<int>& H) {

    int cnt = 1;
    stack<int> st;

    st.push(H[0]);

    for (int i = 1; i < H.size(); i++)
    {
        if (H[i] > st.top())
        {
            st.push(H[i]);
            cnt++;
        }
        else if (H[i] < st.top())
        {
            st.pop();

            if (!st.empty())
            {
                i--;
                continue;
            }

            st.push(H[i]);
            cnt++;
        }
    }

    return cnt;
}