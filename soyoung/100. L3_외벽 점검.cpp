#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    
    int answer = -1;
    int N = weak.size();

    //next_permutation�� ���� sort
    sort(dist.begin(), dist.end());

    for (int i = 0; i < N; i++)
    {
        //������� ��ȯ
        int tmp = weak[0] + n;
        for (int j = 1; j < N; j++)    weak[j - 1] = weak[j];
        weak[N - 1] = tmp;

        //ģ���� ���� �� ��ġ
        do
        {
            int w = 0;  //������� index
            int d = 0;  //ģ���� index
            //���õǴ� ģ�� ��(1~dist.size())
            //ģ�� �Ѹ��� �� �� �ִ� ����������� ����Ž��
            for (d = 0; d < dist.size(); d++)
            {
                int next = weak[w] + dist[d];
                
                while (next >= weak[w])
                {
                    w++;
                    if (w == N)    break;
                }
                
                if (w == N)    break;
            }

            //��� ��������� Ž���Ǹ�, �ּ� ���� ģ�� �� ����
            if (w == N)
            {
                if (answer < 0 || d + 1 < answer)
                    answer = d + 1;
            }

        } while (next_permutation(dist.begin(), dist.end()));

    }

    return answer;
}

//Ref::: https://tech.kakao.com/2019/10/02/kakao-blind-recruitment-2020-round1/, https://blog.naver.com/iambigman97/221906281220, https://algosu.tistory.com/44