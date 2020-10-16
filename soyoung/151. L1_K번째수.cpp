#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> arr;

    for (int x = 0; x < commands.size(); x++)
    {
        int i = commands[x][0];
        int j = commands[x][1];
        int k = commands[x][2];

        arr.assign(array.begin() + i - 1, array.begin() + j);
        sort(arr.begin(), arr.end());
        answer.push_back(arr[k - 1]);
    }
    return answer;
}