#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//가중치 정렬(오름차순)
bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}
//부모노드 찾기
int getParent(vector<int>& parent, int x) {
	//부모노드인경우 그대로 리턴
	if (parent[x] == x) return x;
	//최상위 부모노드 찾기
	return parent[x] = getParent(parent, parent[x]);
}
//부모노드 병합
void unionParent(vector<int>& parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	//작은 노드의 부모로 병합
	a < b ? parent[b] = a : parent[a] = b;
}
//부모노드 비교
bool find(vector<int>& parent, int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	//동일한지 여부 리턴 (사이클 방지)
	return a == b;
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0, max = 0;
	//가중치 정렬
	sort(costs.begin(), costs.end(), cmp);
	//제일 가중치 높은 노드 찾기
	for (auto a : costs) if (max < a[1]) max = a[1];
	//부모노드 생성, 초기화
	vector<int> parent;
	for (int i = 0; i <= max; i++) parent.emplace_back(i);
	//가중치 순회
	for (auto a : costs) {
		//부모노드가 다른 경우 (사이클 생성x)
		if (!find(parent, a[0], a[1])) {
			//결과에 가중치 추가
			answer += a[2];
			//부모노드 병합
			unionParent(parent, a[0], a[1]);
		}
	}
	return answer;
}

//최소신장트리 이용 - 크루스칼 알고리즘
//ref: https://mungto.tistory.com/47
