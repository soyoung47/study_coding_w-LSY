#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(arr1[i] | arr2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        string str = "";

        for (int j = 0; j < n; j++)
        {
            int tmp = num % 2;

            if (tmp == 0)
                str = " " + str;
            else
                str = "#" + str;

            num /= 2;
        }

        answer.push_back(str);
    }
    return answer;
}