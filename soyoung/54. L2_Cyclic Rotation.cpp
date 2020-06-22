//https://app.codility.com/demo/results/trainingBFE8XM-P53/

#include <deque>

vector<int> solution(vector<int>& A, int K) {

    vector<int> answer;
    deque<int> dq;

    if (A.size() > 0)
    {
        //put array into q
        for (int i = 0; i < A.size(); i++)
            dq.push_back(A[i]);

        //rotation(k)
        for (int j = 0; j < K; j++)
        {
            int last = dq.back();
            dq.pop_back();
            dq.push_front(last);
        }

        while (!dq.empty())
        {
            int ans = dq.front();
            answer.push_back(ans);
            dq.pop_front();
        }
    }

    return answer;
}