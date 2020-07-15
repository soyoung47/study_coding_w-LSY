/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingK4PTC7-MMW/
*/
#include <stack>

int solution(vector<int> &A, vector<int> &B) {
    
    stack<int> st;
    int cnt = 0;
    
    for(int i=0; i<A.size(); i++)
    {
        if(B[i] == 1)   st.push(i);
        else
        {
            while(!st.empty())
            {
                int ind = st.top();
                cnt--;
                if(A[i] > A[ind])   st.pop();
                else    break;
            }
        }
        cnt++;
    }
    
    return cnt;
}
