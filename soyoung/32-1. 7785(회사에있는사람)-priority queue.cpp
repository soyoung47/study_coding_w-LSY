#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
	int n=0;
	cin>>n;

	priority_queue<string> enter;
	priority_queue<string> leave;
	string name, inout;

	for(int i=0; i<n; i++)
	{
		cin>>name>>inout;

		if(inout=="enter")
			enter.push(name);
		else
			leave.push(name);
	}

	int size = enter.size();
	for(int a=0; a<size; a++)
	{
		string ch_enter = enter.top();
		enter.pop();
		if(!leave.empty())
		{
			string ch_leave = leave.top();
			if(ch_enter==ch_leave)
				leave.pop();
			else
				cout<<ch_enter<<"\n";
		}
		else
			cout<<ch_enter<<"\n";
	}
}