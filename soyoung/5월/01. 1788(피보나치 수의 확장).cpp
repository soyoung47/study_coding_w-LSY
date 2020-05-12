#include <iostream>
using namespace std;

int n;
long long F[1000001];
long long ans, check;	//양수,음수,0

int main()
{
	cin>>n;

	F[0]=0; F[1]=1;
	for(int i=2; i<=abs(n); i++)
	{
		F[i] = (F[i-1] + F[i-2]) % 1000000000;
	}

	if(n<0 && abs(n)%2==0)
		ans = (-1)*F[abs(n)];
	else
		ans = F[abs(n)];

	if(ans>0)	check=1;
	else if(ans<0)	check=-1;
	else	check=0;

	ans = abs(ans) % 1000000000;

	cout<<check<<"\n"<<ans<<"\n";
}