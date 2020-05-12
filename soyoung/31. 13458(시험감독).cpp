#include<iostream>
using namespace std;

int main()
{
	int N=0, B=0, C=0;
	int A[1000001]={0};
	long ans=0;
	
	
	cin>>N;
	
	for(int i=0; i<N; i++)
		cin>>A[i];

	cin>>B>>C;

	for(int j=0; j<N; j++)
	{
		int a = A[j] - B;
		int k=0; 
		
		if(a>0)
		{
			int b = a/C;
			if(a%C==0)
				ans += b+1;
			else
				ans += b+2;
		}
		else
			ans++;
	}
	
	cout<<ans;
}