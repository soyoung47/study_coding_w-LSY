# 이진 탐색 / 이분 탐색 / Binary Search
## 이진 탐색이란?
* 정렬된 데이터에서 원하는 값을 찾기 위한 탐색법으로, 최소값 최대값 범위 이내에서 중앙값을 구해 구하려는 값과 크기를 비교하며 범위를 좁혀나간다

## 어떻게 작동하는가?
1.  값을 정렬
2.  최소값 - 최대값 범위에서 중간값 구해, 구하려는 값과 비교
3.
  i.   (구하려는 값 = 중간값) 이면, 원하는 값을 찾았으므로 반복 종료
  ii.  (구하려는 값 > 중간값) 이면, 중간값보다 높은 범위를 찾으면 되므로 최소값을 중간값+1의 값으로 업데이트
  iii. (구하려는 값 < 중간값) 이면, 중간값보다 낮은 범위를 찾으면 되므로 최대값을 중간값-1의 값으로 업데이트
4.  3번의 과정을 주어진 값을 찾거나, 최소값<=최대값이 유지되는 동안 반복

## 구현
* 방법1. 반복문 이용
``` C++
int BSearch(int arr[], int target){
  int min = 0;
  int max = arr.size() - 1;
  while (min <= max){
    avg = (low + high) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) max = mid - 1;
    else if (arr[mid] < target) min = mid + 1;
  }
  return -1;
}
```
* 방법2. 재귀함수 이용
``` C++
int BSearch_recursive(int arr[], int target, int min, int max){
  if (min > max) return -1;
  int avg = (min + max) / 2;
  if (arr[avg] == target) return avg;
  else if (arr[avg] > target)
    return BSearch_recursive(arr, target, min, avg-1);
  else if (arr[avg] < target)
    return BSearch_recursive(arr, target, avg+1, max);
}
```
## 시간 복잡도
* O(logN)
   * 반복문을 돌 때마다 범위가 N, N/2, N/4, N/8, ..., 1 로 절반씩 감소
   * 1에서 2씩 k번 곱해주면 N이 되므로 1*2^k = N
   * 양변에 log2를 취하면 log2(2^k) = log2(N)
   * k = log(N)
 
 
*references: https://cjh5414.github.io/binary-search/


