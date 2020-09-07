#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct food_T
{
    int time, ind;
};

bool comp_time(food_T a, food_T b)
{
    return a.time > b.time;
}

bool comp_ind(food_T a, food_T b)
{
    return a.ind < b.ind;
}
int solution(vector<int> food_times, long long k) {

    int size = food_times.size();

    vector<food_T> tray;
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        tray.push_back({ food_times[i], i + 1 });
        sum += food_times[i];
    }

    if (sum <= k)    return -1; 

    //음식 섭취 시간 기준 내림차순
    sort(tray.begin(), tray.end(), comp_time);

    int j;
    long long food =0, eat = 0;

    for (j = tray.size()-1; j >= 0; j--)
    {
        eat = (tray[j].time - food) * tray.size();
        if (k <= eat) break;
        k -= eat;
        food = tray[j].time;
        tray.pop_back();
    }

    //index 기준 오름차순
    sort(tray.begin(), tray.end(), comp_ind);
    return tray[k % tray.size()].ind;
}