/*
    Time Complexity: O(N)
    Result:::https://app.codility.com/demo/results/trainingFV7YB6-DPC/
    Reference:::https://blog.naver.com/egohim/220638198557
*/
int solution(vector<int>& A) {

    int size = A.size();
    vector<int> left(size, 0); //순방향
    vector<int> right(size, 0); //역방향
    int max = 0;

    if (size == 3) return max;

    for (int i = 1; i < size - 1; i++)
    {
        left[i] = (0 > left[i - 1] + A[i]) ? 0 : left[i - 1] + A[i];

        int ind = size - 1 - i;
        right[ind] = (0 > right[ind + 1] + A[ind]) ? 0 : right[ind + 1] + A[ind];
    }

    for (int j = 1; j < size - 1; ++j)
        max = (max > left[j - 1] + right[j + 1]) ? max : left[j - 1] + right[j + 1];

    return max;
}
