/*
    Time Complexity: O(N)
    Result::: https://app.codility.com/demo/results/trainingGVHNXH-ZD9/
    Reference::: http://dal4segno.github.io/algorithm/codility-10-primes-and-composite-numbers/
*/
int solution(vector<int>& A) {

    vector<int> peak, dist;
    int size = A.size();

    if (size < 3)  return 0;

    //Find Peaks
    for (int p = 1; p < size - 1; p++)
    {
        if (A[p] > A[p - 1] && A[p] > A[p + 1])
            peak.push_back(p);
    }

    //Find Number of Max Flags
    int peak_size = peak.size();
    for (int k = 2; k <= peak_size; k++)
    {
        int p = 0, q = 1;
        int flag = 1;
        while (q < peak_size && flag < k)
        {
            if (peak[q] - peak[p] >= k)
            {
                flag++;
                p = q;
            }
            q++;
        }

        if (flag < k)    return k - 1;
    }

    return peak_size;
}

//{ 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 };    //2