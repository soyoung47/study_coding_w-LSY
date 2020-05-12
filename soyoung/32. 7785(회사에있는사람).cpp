#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	int n=0;
	cin>>n;

	set<string> enter;
	string name, inout;

	for(int i=0; i<n; i++)
	{
		cin>>name>>inout;

		if(inout=="enter")
			enter.insert(name);
		else
			enter.erase(name);
	}

	for(auto a=enter.rbegin(); a!= enter.rend(); a++ )
	{
		cout<<*a<<"\n";
	}
}