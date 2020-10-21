/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingPEYE4Z-B6J/
*/
#include <stack>

int solution(string& S) {

    int size = S.length();
    stack<char> st;

    if (size % 2 != 0 && size != 0)  return 0;

    for (int i = 0; i < size; i++)
    {
        if (S[i] == '(') st.push(S[i]);
        else
        {
            if (st.empty())  return 0;
            else    st.pop();
        }
    }

    if (st.empty())    return 1;
    else    return 0;
}