#include <stdio.h>
using namespace std;
int arr[1001][3], dp[1001][3]; //#house, GRB
//최저 비용 계산
int calcMin(int a, int b){return a<b? a: b;}

int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        //각 집 RGB 색칠 비용
        scanf("%d %d %d", &arr[i+1][0], &arr[i+1][1], &arr[i+1][2]);
    }
    for (int i=0; i<N; i++){
        //해당 컬러 제외 두 컬러 중 최소값 + 현재 비용
        dp[i+1][0] = calcMin(dp[i][1], dp[i][2])+arr[i+1][0];
        dp[i+1][1] = calcMin(dp[i][0], dp[i][2])+arr[i+1][1];
        dp[i+1][2] = calcMin(dp[i][0], dp[i][1])+arr[i+1][2];
    }
    printf("%d", calcMin(calcMin(dp[N][0], dp[N][1]), dp[N][2]));

    return 0;
}

//https://m.blog.naver.com/occidere/220785383050
