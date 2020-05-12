#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int n;
long long x[1001], y[1001];
vector<pair<long long,pair<int,int>>> v; //(dist, from_node, to_node)
int parent[1001];
double e;
double emoney;

int find(int x)
{
	if(parent[x]==x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
bool sameparent(int x, int y)
{
	x = find(x);
	y = find(y);

	//부모가 같으면 true(연결), 아니면 false(연결안됨)
	if(x!=y)
		return false;
	else
		return true;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	//연결 안되어있으면 연결
	if(x!=y)
		parent[y] = x;
}
long long cal(int from, int to)
{
    long long new_x,new_y;
    
    new_x = x[to]-x[from];
    new_y = y[to]-y[from];
    
    return (new_x*new_x + new_y*new_y);
}
void check()
{
	//가중치 작은 값부터 큰값순으로 정렬
	sort(v.begin(), v.end());

	//parent 배열 초기화
	for(int i=0; i<n; i++)
		parent[i] = i;

	//mst(크루스칼알고리즘)
	for(int j=0; j<v.size(); j++)
	{
		pair<int, int> p = v[j].second;

		//가장 작은 가중치를 가진 간선이 연결 되어있지 않다면
		if(!sameparent(p.first, p.second))	
		{
			Union(p.first,p.second);//연결
			emoney += v[j].first;//가중치 더하기
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int t;
	cin>>t;

	for(test_case = 1; test_case <= t; ++test_case)
	{
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(parent, 0, sizeof(parent));
		v.clear();
		emoney = 0;
		
		cin>>n;
        for(int i=0; i<n; i++)
            cin>>x[i];
        for(int j=0; j<n; j++)
            cin>>y[j];
        cin>>e;

		for(int a=0; a<n; a++)
		{
			for(int b=0; b<n; b++)
			{
				if(a==b)	continue;
				long long dist = cal(a, b);
				v.push_back(make_pair(dist, make_pair(a,b)));
			}
		}
        
        check();

		long long answer = e*emoney+0.5;

		cout<<"#"<<test_case<<" "<<answer<<"\n";
	}
	return 0;
}