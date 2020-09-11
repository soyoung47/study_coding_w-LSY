#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> cache;
    int size = cities.size();

    if (cacheSize == 0) return size * 5;

    for (int i = 0; i < size; i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);

        auto it = find(cache.begin(), cache.end(), cities[i]);

        if (it == cache.end())
        {
            if (cache.size() == cacheSize)
            {                
                cache.pop_front();
            }

            answer += 5;
        }
        else
        {
            answer += 1;
            cache.erase(it);
        }

        cache.push_back(cities[i]);
    }

    return answer;
}