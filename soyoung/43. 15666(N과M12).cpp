#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int arr[10]={0};
int output[10]={0};
set<vector<int>> s;

void check(int index, int cnt)
{
	if(cnt==M)
	{
		vector<int> v;
		for(int z=0; z<M; z++)
			v.push_back(output[z]);
		sort(v.begin(), v.end());
		s.insert(v);
		return;
	}

	for(int k=index; k<N; k++)
	{
		output[cnt] = arr[k];
		check(k, cnt+1);
	}
}
int main()
{
	cin>>N>>M;

	for(int i=0; i<N; i++)
		cin>>arr[i];

	check(0,0);

	for(auto a=s.begin(); a!=s.end(); a++)
	{
		vector<int> p = *a;

		for(int b=0; b<p.size(); b++)
			cout<<p[b]<<" ";

		cout<<"\n";
	}
}