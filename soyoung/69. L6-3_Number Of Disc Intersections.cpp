/*
    Time Complexity: O(N*log(N)) or O(N)
    Result:::https://app.codility.com/demo/results/trainingJEM3KS-8MC/
    Reference:::http://www.lucainvernizzi.net/blog/2014/11/21/codility-beta-challenge-number-of-disc-intersections/
*/
#include <algorithm>

bool cmp(pair<long long, int> a, pair<long long, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int solution(vector<int>& A) {

    int intersection = 0, active = 0;
    vector<pair<long long, int>> disc;

    for (int i = 0; i < A.size(); i++)
    {
        disc.push_back(make_pair((long long)i - A[i], 1));
        disc.push_back(make_pair((long long)i + A[i], -1));
    }

    sort(disc.begin(), disc.end(), cmp);

    for (int j = 0; j < disc.size(); j++)
    {
        if (disc[j].second > 0)
            intersection += active * disc[j].second;
        active += disc[j].second;
    }

    if (intersection > 10000000) return -1;

    return intersection;
}