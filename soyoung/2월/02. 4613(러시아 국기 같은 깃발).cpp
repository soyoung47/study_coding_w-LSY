#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	int N, M, max, sumFL, w, b, r;
	char flag;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>N>>M;

		int **color = new int*[N];
		for(int i=0; i<N; i++)
			color[i] = new int[3];

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<3; j++)
				color[i][j] = 0;
		}

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				cin>>flag;
				if(flag=='W')
					color[i][0]++;
				else if(flag=='B')
					color[i][1]++;
				else if(flag=='R') //else if ��� else�� ��ü����
					color[i][2]++;
			}
		}

		sumFL=color[0][0]+color[N-1][2];	//ù°��, ��������(W, R)
		max=0, w=0, b=0, r=0;

		for(int i=1; i<N-1; i++)	//b�� �������� �Ǵ�
		{
			for(int j=i+1; j<N; j++)	//r�� �������� �Ǵ�
			{
				for(int k=1; k<i; k++)	//w�� ���� �� �� �ִ� ���
					w += color[k][0];
				for(int k=i; k<j; k++)	//b�� ���� �� �� �ִ� ���
					b += color[k][1];
				for(int k=j; k<N-1; k++)	//r�� ���� �� �� �ִ� ���
					r += color[k][2];

				if(max < w+b+r)
					max = w+b+r;

				w=0, b=0, r=0;
			}
		}		

		cout<<"#"<<test_case<<" "<<N*M-max-sumFL<<"\n";
	}
	return 0;
}