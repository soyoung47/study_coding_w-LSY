#include<iostream>
#include<algorithm>
using namespace std;

int N, ans;
int T[16];
int P[16];

void go(int day, int pay)
{
	if(day==N+1)
	{
		if(ans<pay)
			ans = pay;
		return;
	}

	if(day>N+1)
		return;

	//��� �ϴ� ���(����o)
	go(day+T[day], pay+P[day]);
	//��� ���ϴ� ���(����x)
	go(day+1, pay);	
}
int main()
{
	N=0, ans=0;
	cin>>N;

	fill(T, T+16, 1);
	fill(P, P+16, 0);

	for(int i=1; i<=N; i++)
		cin>>T[i]>>P[i];

	go(1,0);

	cout<<ans;
}