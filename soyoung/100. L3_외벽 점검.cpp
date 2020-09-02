#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    
    int answer = -1;
    int N = weak.size();

    //next_permutation을 위해 sort
    sort(dist.begin(), dist.end());

    for (int i = 0; i < N; i++)
    {
        //취약지점 순환
        int tmp = weak[0] + n;
        for (int j = 1; j < N; j++)    weak[j - 1] = weak[j];
        weak[N - 1] = tmp;

        //친구들 선택 및 배치
        do
        {
            int w = 0;  //취약지점 index
            int d = 0;  //친구들 index
            //선택되는 친구 수(1~dist.size())
            //친구 한명이 갈 수 있는 취약지점까지 완전탐색
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

            //모든 취약지점이 탐색되면, 최소 투입 친구 수 저장
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