#include<iostream>
#include<memory.h>
#include<utility>
#include<math.h>
using namespace std;

bool visit[15];
int dist[15][15];
pair<int,int> p[15];
int ans, N;

void toHome(int index, int sum, int cnt)
{
	if(cnt==N)
	{
		sum += dist[index][1];

		if(ans>sum)
			ans = sum;

		return;
	}

	for(int k=2; k<N+2; k++)
	{
		if(visit[k])	continue;
		visit[k] = true;

		toHome(k, sum + dist[index][k], cnt+1);
		visit[k] = false;
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>N;

		memset(visit, false, sizeof(visit));
		memset(dist, 0, sizeof(dist));

		for(int i=0; i<N+2; i++)
			cin>>p[i].first>>p[i].second;
		
		for(int a=0; a<N+2; a++)
		{
			for(int b=0; b<N+2; b++)
				dist[a][b] = abs(p[a].first-p[b].first) + abs(p[a].second-p[b].second);
		}

		ans = 9*1111111;
		visit[0] = true;
		toHome(0,0,0);

		cout<<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}