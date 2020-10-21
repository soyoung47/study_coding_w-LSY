//time complexity: O(N)
//https://app.codility.com/demo/results/trainingWJ3F73-J5E/

int solution(int X, vector<int>& A) {

    int ans = -1;
    int cnt = 0;
    bool isFall[100001] = { false };

    for (int i = 0; i < A.size(); i++)
    {

        if (isFall[A[i]])    continue;

        isFall[A[i]] = true;
        cnt++;

        if (cnt == X)
        {
            ans = i;
            break;
        }
    }

    return ans;
}