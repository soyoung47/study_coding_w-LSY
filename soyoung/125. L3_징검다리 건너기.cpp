//https://programmers.co.kr/learn/courses/30/lessons/64062

#include <string>
#include <vector>
#include <set>
using namespace std;

bool check(int mid, vector<int>& stones, int& k)
{
    int zero = 0;

    for (int i = 0; i < stones.size(); i++)
    {
        int niniz = stones[i] - mid;
        
        if (niniz <= 0)
            zero++;           
        else
            zero = 0;

        if (zero >= k)   return false;
    }

    return true;
}

int solution(vector<int> stones, int k) {

    set<int> s;
    for (int i = 0; i < stones.size(); i++)
        s.insert(stones[i]);
        
    int min = *s.begin();
    int max = *s.rbegin();

    while (min <= max)
    {
        int mid = (min + max) / 2;
        if (check(mid, stones, k))
            min = mid + 1;
        else
            max = mid - 1;
    }  

    return min;
}

//Ref:::https://ksdyoung.tistory.com/69
//++:::O(n): https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/