#include<iostream>
using namespace std;

int main()
{
	int n=0; 
	cin>>n;

	for(int i=1; i<2*n; i++)
	{
		if(i<=n)
		{
			for(int a=0; a<n-i; a++)
				cout<<" ";
			for(int b=0; b<2*i-1; b++)
				cout<<"*";
		}
		else
		{
			int k = 2*n-i;
			for(int a=0; a<n-k; a++)
				cout<<" ";
			for(int b=0; b<2*k-1; b++)
				cout<<"*";
		}
		cout<<"\n";
	}
}