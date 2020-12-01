//https://programmers.co.kr/learn/courses/30/lessons/43236

/***Solution 2***/
#include <algorithm>
#include <vector>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {

    sort(rocks.begin(), rocks.end());

    int size = rocks.size();
    vector<int> dist(size + 1, 0);  //������ ���� �Ÿ�
    
    int last = 0;
    for (int i=0; i<size; i++)
    {
        dist[i] = rocks[i] - last;
        last = rocks[i];
    }
    dist[size] = distance - last;

    int start = 1, end = distance, mid;
    while (start < end)
    {
        mid = (start + end + 1) / 2;

        int cnt = 0, prev = 0;
        for (int d : dist)
        {
            if (mid > d + prev)
            {
                cnt++;
                prev += d;
            }
            else
                prev = 0;
        }

        if (cnt <= n)   start = mid;
        else    end = mid - 1;
    }

    return start;
}

//REF:::https://mind-devlog.tistory.com/47



/***Solution 1***/
#include <algorithm>
#include <vector>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int size = rocks.size();
    sort(rocks.begin(), rocks.end());

    int start = 1, end = distance, mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        int cnt = 0, ind = -1;  //������ ���� ����, ������ ���õ�(���ŵ��� ����) ���� index
        for (int i = 0; i <= size; ++i)
        {
            /*  ó�� �����ϴ� �����̸� (�Ÿ� = �����Ϸ��� ���� ��ġ).
                ó�� �����ϴ� ������ �ƴϸ� (�Ÿ� = �����Ϸ��� ���� ��ġ - ������ ������ ���� ��ġ).
                �̶� �����Ϸ��� ���� ��ġ�� �������̸� (�Ÿ� = ������ - ������ ���� ��ġ)
            */
            int dist = ind == -1 ? rocks[i] : (i == size ? distance - rocks.back() : rocks[i] - rocks[ind]);

            //�Ÿ��� mid ���� ������ �����ϰ�, �ƴϸ� �������� �ʴ´�.
            if (dist < mid)  cnt++;
            else    ind = i;    //������ ���õ� �������� �Ÿ� ����� ���� index�� ����
        }

        if (cnt <= n)
        {
            start = mid + 1;
            answer = answer > mid ? answer : mid;
        }
        else    end = mid - 1;
    }

    return answer;
}

//REF:::https://dokrsky.tistory.com/81