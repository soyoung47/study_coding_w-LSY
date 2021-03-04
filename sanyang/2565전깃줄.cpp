//엉키지 않게 하는 방법: 한쪽 전봇대 sort 후 LIS 적용
//A-B 전봇대가 두 대 있으므로 연결 저장하는 vector pair 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, a, b, ans=0;
    scanf("%d", &N);
    int dp[101]; //전깃줄의 개수 (100이하)
    
    vector<pair<int, int>> v;
    for (int i=0; i<N; i++){
        //전봇대A:a, 전봇대B:b
        scanf("%d %d", &a, &b);
        v.emplace_back(a,b);
    }
    //A기준으로 정렬
    sort(v.begin(), v.end());
    
    for (int i=0; i<N; i++){
        dp[i]=1;
        for (int j=0; j<i; j++){
            //b값으로 LIS
            if (v[i].second > v[j].second && dp[i]<=dp[j]+1) dp[i] = dp[j]+1;
        }
        if (dp[i]>ans) ans=dp[i];
    }
    
    printf("%d", N-ans);
    return 0;
}

//ref: https://hwan-shell.tistory.com/310
