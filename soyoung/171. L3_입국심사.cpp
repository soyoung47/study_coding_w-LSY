//https://programmers.co.kr/learn/courses/30/lessons/43238

#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {

    //�ð� �������� ����
    sort(times.begin(), times.end());

    long long min = 1;
    long long max = (long long)times.back() * n;
    long long answer = max;

    //�ҿ�Ǵ� �ð��� �������� �̺� Ž��
    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long cnt = 0;  //�ҿ�ð�(mid) ���� �ɻ��� ��� ��

        //�ҿ�ð�(mid) ���� �ɻ��� �� �ִ� ��� �� üũ
        for (int t : times)
            cnt += mid / t;

        //�ҿ�ð�(mid) ���� n���� ��� �ɻ����� ���� ���
        if (cnt < n)    min = mid + 1;
        //�ҿ�ð�(mid) ���� n���� ��� �ɻ��� ���
        else
        {
            max = mid - 1;
            answer = answer < mid ? answer : mid;
        }
    }

    return answer;
}

//REF:::https://blog.naver.com/cocokelly1229/222078992832