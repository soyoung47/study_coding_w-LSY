/*
    Time Complexity: O(N*log(N)) or O(N)
    Result:::https://app.codility.com/demo/results/training9ARFJ5-YW8/
*/
#include <map>

int solution(vector<int>& A) {

    map<int, int> m;

    for (int i = 0; i < A.size(); i++)
        m[A[i]] += 1;

    int max = 0;
    int elem = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        if (max < iter->second)
        {
            max = iter->second;
            elem = iter->first;
        }
    }

    if (max > A.size() / 2)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] == elem)
                return j;
        }
    }
    else
        return -1;
}
