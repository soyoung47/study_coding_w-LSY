//time complexity : O(N) or O(N*log(N))
//https://app.codility.com/demo/results/trainingRU8RDE-M9G/

int solution(vector<int>& A) {

    int unpair = A[0];
    
    for (int i = 1; i < A.size(); i++)
        unpair ^= A[i];

    return unpair;
}