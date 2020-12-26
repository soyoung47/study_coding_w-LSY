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




---
- [md 파일 작성 방법 1](https://blog.naver.com/vkfkdto0209/222141824686)
- [md 파일 작성 방법 2](https://blog.naver.com/jooeun0502/221956294941)
- [md 파일 작성 방법 3] GitHub Docs(https://docs.github.com/en/free-pro-team@latest/github/writing-on-github/getting-started-with-writing-and-formatting-on-github)

