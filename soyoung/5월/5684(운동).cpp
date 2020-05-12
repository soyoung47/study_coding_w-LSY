//#include<iostream>
//#include<memory.h>
//#include<utility>
//#include<vector>
//using namespace std;
//
//#define MAX 405
//bool visit[MAX];
//int N,M,ans;
//vector<pair<int,int>> v[MAX];//v[from].push_back(make_pair(to, dist));
//
//int MIN(int a, int b)
//{
//	if(a<b)
//		return a;
//	return b;
//}
//
//void go(int cur, int sum, int start)//DFS
//{
//	visit[cur] = true;
//
//	for(int x=0; x<v[cur].size(); x++)
//	{
//		int next = v[cur][x].first;
//		int dist = v[cur][x].second;
//
//		if(!visit[next])
//		{
//			if(sum+dist < ans)
//				go(next, sum+dist, start);
//		}
//		else
//		{
//			if(next==start)	//시작정점으로 되돌아왔다면 cycle: 최소값저장
//				ans = MIN(ans,sum+dist);
//		}
//	}
//}
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//	
//	cin>>T;
//	
//	for(test_case = 1; test_case <= T; ++test_case)
//	{
//		for(int k=0; k<MAX; k++)
//			v[k].clear();
//		
//		ans = 987654321;
//
//		cin>>N>>M;
//
//		for(int i=0; i<M; i++)
//		{
//			int s,e,c;
//			cin>>s>>e>>c;
//			v[s].push_back(make_pair(e,c));
//		}
//		
//		for(int j=1; j<=N; j++)
//		{
//			if(v[j].empty())	continue;
//			
//			memset(visit, false, sizeof(visit));
//			go(j,0,j);
//		}
//
//		if(ans==987654321)
//			ans = -1;
//
//		cout<<"#"<<test_case<<" "<<ans<<"\n";
//
//	}
//	return 0;
//}