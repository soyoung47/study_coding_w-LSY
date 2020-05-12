#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

bool contact[101][101];
bool visited[101];
int check[101];

void callToperson(int start)
{
	queue<int> q;
	int ord=0;

	q.push(start);
	visited[start] = true;
	check[start] = ord + 1;
	
	while(!q.empty())
	{
		int size = q.size();
 		ord++;

		while(size>0)
		{
            int cur = q.front();
            q.pop();
           
			for(int k=0; k<101; k++)
			{
				if(!visited[k] && contact[cur][k])
				{
					q.push(k);
					visited[k]=true;
					check[k] = ord;
				}
			}
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N=0, first =0, from, to;
		cin>>N>>first;

		memset(contact, false, sizeof(contact));
		memset(visited, false, sizeof(visited));
		memset(check, 0, sizeof(check));

		//input
		for(int a=0; a<N/2; a++)
		{
			cin>>from>>to;
			contact[from][to] = true;
		}

		callToperson(first);

		//마지막에 연락받은 사람 중 번호가 큰 사람
		int max=-1, last=-1;
		for(int b=0; b<101; b++)
		{
			if(check[b]>=last)
			{
				last = check[b];
				max = b;
			}
		}

		cout<<"#"<<test_case<<" "<<max<<"\n";
	}
	return 0;
}