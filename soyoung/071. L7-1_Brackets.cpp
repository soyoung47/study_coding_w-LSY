/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/training6W7DPR-GCJ/
*/
#include <stack>

int solution(string& S) {

    int size = S.length();
    stack<char> st;

    if (size == 0) return 1;
    if (size % 2 != 0)   return 0;

    for (int i = 0; i < size; i++)
    {
        if (S[i] == '(' || S[i] == '[' || S[i] == '{')
            st.push(S[i]);
        else
        {
            char ch = st.top();
            char s = S[i];

            if ((ch == '(' && s == ')') || (ch == '[' && s == ']') || (ch == '{' && s == '}'))
                st.pop();
            else
                return 0;
        }
    }

    if (st.empty())
        return 1;
    else
        return 0;
}


