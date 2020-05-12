#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	char ans1, ans2;

	cin>>a>>b>>c;
	
	ans2 = '=';
	if(a+b==c)
		ans1 = '+';
	else if(a-b==c)
		ans1 = '-';
	else if(a*b==c)
		ans1 = '*';
	else if(a/b==c)
		ans1 = '/';
	else
	{
		ans1 = '=';
		if(a==b+c)
			ans2 = '+';
		else if(a==b-c)
			ans2 = '-';
		else if(a==b*c)
			ans2 = '*';
		else
			ans2 = '/';
	}

	cout<<a<<ans1<<b<<ans2<<c;

	return 0;
}