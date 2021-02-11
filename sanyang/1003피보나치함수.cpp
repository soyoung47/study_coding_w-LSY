#include <stdio.h>
using namespace std;

int main(){
    int T, N, F[41] = {0,1};
    //0 1 출력 횟수
    //0: 1 0, 1: 0 1
    //나머지 규칙: F[n] = F[n-1] + F[-2]
    for (int n=2; n<=40; n++) F[n] = F[n-1] + F[n-2];
    scanf("%d", &T);
    for (int tc=0; tc<T; tc++){
        scanf("%d", &N);
        if (N==0) printf("1 0\n");
        else if (N==1) printf("0 1\n");
        else printf("%d %d\n", F[N-1], F[N]);
    }
    return 0;
}

//https://m.blog.naver.com/dntkrl79/222062232208
