#include<iostream>
#include<stack>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10, N;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>N;
		int num=0; 
		stack<int>	pw;

		for(int i=0; i<N; i++)
		{
			scanf("%1d",&num);
			if(pw.empty() || (pw.top() != num))	
				pw.push(num);
			else	
				pw.pop();
		}
		
		int pwArr[100] = {0};
		int size = pw.size();
		for(int j=size-1; j>-1; j--)
		{
			pwArr[j] = pw.top();
			pw.pop();
		}

		cout<<"#"<<test_case<<" ";
		for(int k=0; k<size; k++)
			cout<<pwArr[k];
		cout<<"\n";
	}
	return 0;
}

#include<vector>
vector<int> pw;
vector<int> pwFind()
{
	int cnt=0;
	for(int a=0; a<pw.size()-1; a++)
	{		
		if(pw[a]==pw[a+1])
		{
			pw.erase(pw.begin()+a, pw.begin()+a+2);
			a-=2;
		}
		else
			cnt++;
	}

	if(cnt!=pw.size()-1)
	{
		pwFind();
		return pw;
	}
	else
		return pw;		
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10, N;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>N;
		pw.assign(N,0);
		for(int i=0; i<N; i++)
			scanf("%1d",&pw[i]);

		pwFind();
		
		cout<<"#"<<test_case<<" ";
		for(int k=0; k<pw.size(); k++)
			cout<<pw[k];
		cout<<"\n";
	}
	return 0;
}