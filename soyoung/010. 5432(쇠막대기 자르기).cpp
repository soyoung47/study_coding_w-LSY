#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	string laser;
	stack <char>stick;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>laser;

		int cnt=0;
		for(int i=0; i<laser.length(); i++)
		{
			if(laser[i] == '(')
			{
				if(laser[i+1] == ')')
				{
					cnt += stick.size();
					i++;
				}
				else
					stick.push(laser[i]);
			}
			else
			{
				cnt++;
				stick.pop();
			}
		}

		cout<<"#"<<test_case<<" "<<cnt<<"\n";
	}
	return 0;
}