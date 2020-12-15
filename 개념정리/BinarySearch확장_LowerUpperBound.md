``` C++
#include <stdio.h>
#include <algorithm>
using namespace std;

//원하는 값 k이상이 처음 나오는 위치
int lower_bound(int[], int, int); //arr, target, length
//원하는 값 k를 초과한 값이 처음 나오는 위치
int upper_bound(int[], int, int); //arr, target, length

int main(){
    int arr[10]= {9,7,12,18,3,15,4,1,13,5};
    int target = 12; //num to find
    int n = 10; //length of arr

    sort(arr, arr+n); //sorted: 1,3,4,5,7,9,12,13,15,18

    printf("lower bound is arr[%d]\n", lower_bound(arr, target, n));
    printf("upper bound is arr[%d]\n", upper_bound(arr, target, n));
    return 0;
}

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


/*
 <algorithm> LowerBound, UpperBound
 std::lower_bound([배열첫주소],[배열끝주소],target(k),[sort])
 std::upper_bound([배열첫주소],[배열끝주소],target(k),[sort])
 정렬에 입력 안하면 오름차순 정렬
 반환 값으로 bound에 해당하는 주소값 반환, 함숫값에서 배열 처음값 빼줘야 n번째 인덱스

 printf("lower bound is arr[%d]\n", std::lower_bound(&arr[0], &arr[n-1], target) - &arr[0]);
 printf("upper bound is arr[%d]\n", std::upper_bound(&arr[0], &arr[n-1], target) - &arr[0]);
 */
```

//ref: https://bit.ly/37i4QTk
