#include <cstdio>
#include <algorithm>
using namespace std;

int lower_bound(int arr[], int target, int size){
    int min, max, avg;
    min = 0;
    max = size-1;
    //max가 min이하가되면 그 값이 lower bound
    while(min < max){
        avg = (min+max)/2;
        //중앙값이 타겟이랑 같거나 크면 lower bound의 가능성 있으니 최대값 포함
        if (arr[avg] >= target) max = avg;
        else if (arr[avg] < target) min = avg+1;
    }
    return max;
}

int upper_bound(int arr[], int target, int size){
    int min, max, avg;
    min = 0;
    max = size-1;

    while(min < max){
        avg = (min+max)/2;
        //중앙값이 타겟보다 크면 upper bound의 가능성 있음
        if (arr[avg] > target) max = avg;
        else if (arr[avg] <= target) min = avg+1;
    }
    return max;
}

int main(){
    int N, M;
    scanf("%d", &N);
    int cards[500001];
    for (int i=0; i<N; i++){
        scanf("%d", &cards[i]);
    }
    sort(cards, cards+N);
    scanf("%d", &M);
    int targets[500001];
    int results[500001];
    for (int i=0; i<M; i++){
        scanf("%d", &targets[i]);
        results[i] = 0;
    }

    for (int i=0; i<M; i++){
        int lb = lower_bound(cards, targets[i], N);
        int ub = upper_bound(cards, targets[i], N);
        if (ub==N-1 && cards[N-1]==targets[i]) ub++;
        results[i] = ub - lb;
    }

    for (int i=0; i<M; i++) printf("%d ", results[i]);

    return 0;
}
