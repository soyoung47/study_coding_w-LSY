#include<iostream>
#include<memory.h>
#include<string>
using namespace std;

int N, ans;
int wordAlpha[15][26];
int cnt[26];

void wordSet(int idx)
{
	if(idx==N)
	{
		for(int a=0; a<26; a++)
		{
			if(cnt[a]==0)
				return;
		}
		ans++;
		return;
	}
	
	for(int b=0; b<26; b++)
		cnt[b] += wordAlpha[idx][b];
	wordSet(idx+1);

	for(int b=0; b<26; b++)
		cnt[b] -= wordAlpha[idx][b];
	wordSet(idx+1);

}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		N=0, ans=0;
		string word, alphabet="abcdefghijklnmopqrstuvwxyz";

		cin>>N;

		for(int u=0; u<15; u++)
			memset(wordAlpha[u], 0, sizeof(wordAlpha[u]));
		memset(cnt, 0, sizeof(cnt));

		for(int i=0; i<N; i++)
		{
			cin>>word;
			for(int j=0; j<26; j++)
			{
				for(int k=0; k<word.size(); k++)
				{
					if(word[k] == alphabet[j])
						wordAlpha[i][j]++;
				}				
			}
		}
		
		wordSet(0);

		cout<<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}