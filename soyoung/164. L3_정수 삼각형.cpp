//https://programmers.co.kr/learn/courses/30/lessons/43105

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size() - 1;
    vector<vector<int>> dist = triangle;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if(j==0 || dist[i + 1][j] == triangle[i + 1][j])
                dist[i + 1][j] += dist[i][j];
            else
                dist[i + 1][j] = max(dist[i + 1][j], triangle[i + 1][j] + dist[i][j]);

            dist[i + 1][j + 1] += dist[i][j];
        }
    }
    
    return *max_element(dist[n].begin(), dist[n].end());
}