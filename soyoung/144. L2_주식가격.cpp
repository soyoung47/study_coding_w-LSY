//https://programmers.co.kr/learn/courses/30/lessons/42584

/**Solution 2: Stack**/
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size, 0);
    stack<int> st;

    for (int i = size - 2; i >= 0; i--)
    {
        int price = prices[i];
        int cnt = 1;
        while (!st.empty() && price <= prices[st.top()])
        {
            cnt += answer[st.top()];
            st.pop();
        }
        st.push(i);
        answer[i] = cnt;
    }

    return answer;
}

/**Solution 1: ÀÌÁß for¹®**/
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int size = prices.size();
    for (int i = 0; i < size - 1; i++)
    {
        stack<int> st;
        int price = prices[i];
        for (int j = i + 1; j < size; j++)
        {
            st.push(prices[j]);

            if (price > prices[j]) break;
        }
        answer.push_back(st.size());
    }

    answer.push_back(0);
    return answer;
}