# QnA

### [문법]
* 삼항연산자
    - (조건) ? TRUE : FALSE


### [최소 스패닝 트리]
* 스패닝 트리(Spanning Tree)
: 방향이 없는 그래프에서 모든 노드를 포함하면서, 순환되는 경로를 제거한 형태
* 최소 스패닝 트리(Minimal Spanning Tree: MST)
: 가중치의 합이 가장 작은 스패닝 트리

* 대표적인 알고리즘: 프림(Prim), 크루스칼(Kruskal)

    * 프림(Prim)
        * 시작 정점(node)에서 단계적으로 노드 추가하는 방식으로 트리 구성
        * 정점(node) 중심으로 MST 만들어 나가기 때문에 node가 많고, edge가 적은 경우 유리하다.

    * 크루스칼(Kruskal)
        * 사전에 가중치 정보 파악하고, 가중치를 오름차순 정렬하여 트리 구성 (Union-Find 기법)
        * 간선(edge) 중심으로 MST 만들어 나가기 때문에 edge가 많고, node가 적은 경우 유리하다.

    * 정점의 개수가 n이라면, 프림은 O(nlogn), 크루스칼은 O(nlogn) ~ O(n^2logn)의 시간복잡도를 가진다.
    
    
### [하드코딩 기준]
* 데이터 수가 100,000개 미만이면 하드코딩해서 넘어가는 경우가 꽤 있다. 그 이상일 때는 효율적 알고리즘 사용 필요

* 코딩테스트에서 수행시간 1초인 경우, 계산량 1억이 넘어가면 안되는데 데이터 1만개의 경우 1억정도가 나온다.

    * 참고: https://life-with-coding.tistory.com/273

### [Visual Studio(IDE)에서 scanf 오류 발생시]
* scanf가 아니라 scanf_s로 변경하여 사용하도록 권유하고, 빌드 되지 않는 오류 발생
	* 프로젝트 속성 - C/C++ - SDL검사 옵션 (아니오)로 변경하여 해결

### 배열 초기화
1. 정적배열
* 0으로 초기화
	```C++
	int arr[5] = {};
	int arr[5] = {0};
	int arr[5] = {0,};
	```
* 0이 아닌 수로 초기화(예시: 1로 초기화)
	- memset() 함수
		- 1바이트 배열에서는 256 미만의 값, 1바이트 초과 배열에서는 0과 -1만 가능
	```C++
	int arr[5];
	memset(arr, 1, sizeof(arr));	//배열 이름, 초기화값, 배열의 크기
	```
	- fill() 함수
	```C++
	int arr[5];
	fill(arr[0], arr[0]+5, 1);	//시작인덱스, 시작인덱스+원소 개수, 초기화값
	```
	- fill_n() 함수
	```C++
	int arr[5];
	fill(arr[0], 5, 1);	//시작인덱스, 원소 개수, 초기화값
	```
2. 동적배열
```C++
vector<int> n;
n.resize(5);	//배열의 크기
n.resize(5, 0);	//배열의 크기, 초기화값

vector<int> n(5);	//배열의 크기
vector<int> n(5, 0);	//배열의 크기, 초기화값

//2차원 배열
vector<vector<int>> v(a, vector<int>(b, 1));	//axb의 2차원 배열, 1로 초기화
```
---
- [md 파일 작성 방법 1](https://blog.naver.com/vkfkdto0209/222141824686)
- [md 파일 작성 방법 2](https://blog.naver.com/jooeun0502/221956294941)
- [md 파일 작성 방법 3(GitHub Docs)](https://docs.github.com/en/free-pro-team@latest/github/writing-on-github/getting-started-with-writing-and-formatting-on-github)

