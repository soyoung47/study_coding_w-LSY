#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<vector<int>> s;
int N,M;
int arr[8] = {0};
int output[8] = {0};
void check(int cnt)
{	
	if(cnt==M)
	{
		vector<int> v;		
		for(int j=0; j<M; j++)
			v.push_back(output[j]);
		s.insert(v);
		return;
	}

	for(int a=0; a<N; a++)
	{
		output[cnt] = arr[a];
		check(cnt+1);
	}
}
int main()
{
	cin>>N>>M;
	for(int i=0; i<N; i++)
		cin>>arr[i];

	check(0);

	for(auto k=s.begin(); k!=s.end();k++)
	{
		vector<int> tmp = *k;
		for(int j=0; j<tmp.size(); j++)
			cout<<tmp[j]<<" ";
		cout<<"\n";
	}
}