/*
    [solution 2] : unordered_set
    Time Complexity: O(N) or O(N*log(N))
    Result::: https://app.codility.com/demo/results/trainingA9DGQ9-97V/
*/
#include <unordered_set>

int solution(vector<int> &A) {

    unordered_set<int> s;
    
    for(int i=0; i<A.size(); i++)
    {
        s.insert(abs(A[i]));
    }
    
    return s.size();
}


/*
    [solution 1] : unordered_map
    Time Complexity: O(N) or O(N*log(N))
    Result::: https://app.codility.com/demo/results/trainingDG4Y3B-GZE/
*/
#include <unordered_map>

int solution(vector<int> &A) {

    unordered_map<int,int> m;
    
    for(int i=0; i<A.size(); i++)
    {
        m[abs(A[i])] = 1;
    }
    
    return m.size();
}
