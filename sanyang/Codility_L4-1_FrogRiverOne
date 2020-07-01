//Codility_L4-1_CountingElements_FrogRiverOne[Painless]
//https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

#include <set>

int solution(int X, vector<int> &A)
{
    int ans = -1;
    set<int> s;
    for (int i=1; i<=X; i++)  s.insert(i);
    for (int i=0; i<A.size(); i++)
    {
        s.erase(A[i]);
        if (s.empty()==true)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

//result: https://app.codility.com/demo/results/training4DHCM7-HEG/
