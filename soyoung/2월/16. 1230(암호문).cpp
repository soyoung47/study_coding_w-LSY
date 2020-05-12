#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;
vector<int>	pw;
vector<int> Insert()
{
	int x=0, y=0;
	cin>>x>>y;
	vector<int> s(y,0);
	for(int a=0; a<y; a++)
		cin>>s[a];

	pw.insert(pw.begin()+x,s.begin(), s.end());

	return pw;
}
vector<int> Delete()
{
	int x=0, y=0;
	cin>>x>>y;

	pw.erase(pw.begin()+x,pw.begin()+x+y);

	return pw;
}
vector<int> Add()
{
	int y=0, s=0;
	cin>>y;
	for(int a=0; a<y; a++)
	{
		cin>>s;
		pw.push_back(s);
	}

	return pw;
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10, N, n;
	char cmd;
	//freopen("input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>N;
		pw.assign(N,0);
		for(int i=0; i<N; i++)
			cin>>pw[i];

		cin>>n;
		for(int k=0; k<n; k++)
		{
			cin>>cmd;
			switch(cmd){
				case 'I':	Insert();	break;
				case 'D':	Delete();	break;
				case 'A':	Add();	break;
			}
		}
		
		cout<<"#"<<test_case<<" ";
		for(int j=0; j<10; j++)
			cout<<pw[j]<<" ";
		cout<<"\n";
	}
	return 0;
}