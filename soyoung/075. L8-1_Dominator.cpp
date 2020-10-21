/*
    [solution 2]
    Time Complexity: O(N*log(N)) or O(N)
    Result:::https://app.codility.com/demo/results/trainingY2GWXT-V8C/
    Reference:::https://codility.com/media/train/6-Leader.pdf
*/
#include <algorithm>

int solution(vector<int>& A) {

    int leader = 0;
    int size = A.size();
    int cnt = 0;
    int index = 0;

    if (size == 0) return -1;

    vector<int> B = A;
    sort(B.begin(), B.end());
    leader = B[size / 2];

    for (int i = 0; i < size; i++)
    {
        if (A[i] == leader)
        {
            cnt++;
            index = i;
        }
    }

    if (cnt < (size / 2) + 1)    return -1;

    return index;
}

/*
    [solution 1]
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
