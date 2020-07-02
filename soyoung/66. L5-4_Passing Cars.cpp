/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingNFK4QW-5PP/
*/
int solution(vector<int>& A) {

    int cnt = 0;

    int size = A.size();
    vector<int> P(size);
    vector<int> Q(size);

    //sum of cars traveling to the east(P) and cars traveling to the west(Q)
    int p = 0, q = 0;
    for (int k = 0; k < size; k++)
    {
        if (A[k] == 0)
            p++;
        else
            q++;

        P[k] = p;
        Q[k] = q;
    }

    if (size > 1)
    {
        cnt = P[0] * Q[size - 1];
        for (int j = 1; j < size; j++)
        {
            if (P[j] != P[j - 1])
            {
                cnt += Q[size - 1] - Q[j];
            }

            if (cnt > 1000000000)
                return -1;
        }
    }

    return cnt;
}