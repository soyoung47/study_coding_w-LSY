/*
    Time Complexity: O(N*log(N)) or O(N)
    Result:::https://app.codility.com/demo/results/trainingQCURRQ-PK5/
*/
#include <set>

int solution(vector<int>& A) {

    set<int> s;

    for (int i = 0; i < A.size(); i++)
        s.insert(A[i]);

    return s.size();
}