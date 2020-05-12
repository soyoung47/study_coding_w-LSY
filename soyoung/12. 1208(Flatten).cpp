#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10, N, max, min, max_id, min_id, cnt;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin>>N;

		int box[100] = {0};
		max=0, min=100, cnt=N;

		for(int i=0; i<100; i++)
		{
			cin>>box[i];

			if(box[i]>max){	max = box[i];	max_id = i;}
			if(box[i]<min){	min = box[i];	min_id = i;}
		}

		while(max-min>1)
		{
			if(cnt==0)	break;
			
			box[max_id]--;	max--;
			box[min_id]++;	min++;

			for(int k=0; k<100; k++)
			{
				if(box[k]>max){	max = box[k];	max_id = k;}
				if(box[k]<min){	min = box[k];	min_id = k;}
			}

			cnt--;
		}

		cout<<"#"<<test_case<<" "<<max-min<<"\n";
	}
	return 0;
}